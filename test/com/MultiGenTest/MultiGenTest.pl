#! /usr/bin/perl

#
# In the following subroutines:
#   $P - Platform name
#   $V - COM library version
#   $T - Test command to execute
#   $F - File name to create, open modify, or open read-only.
#

%GlobalState = ();

######################################################################

sub InitGlobalState {
    %GlobalState = ( TestPassedCount => 0,
                     TestFailedCount => 0,
		     TestExcludedCount => 0 
		   );
}

######################################################################

sub usage {
    print "Usage: $0 config_file.pl\n";
    exit -1;
}

######################################################################

sub GenerateUniqueFilename {
    my( $P, $V, $T ) = @_;
    my($filename) = "$T-$P-$V.aaf";
    $filename;
}

######################################################################

sub DumpList {
    foreach $item ( @_ ) {
	print "$item ";
    }
    print "\n";
}

######################################################################

sub ExecuteCommand {
    my ( $P, @args ) = @_;

    @sys_args = ( @{$CFG{SysExecArgs}{$P}}, @args );    

    DumpList( @sys_args );

    # FIXME ... started out here wanting to call system() with a
    # list... had trouble with that... but got system() to work if I
    # passed a single string... had trouble getting the return status
    # back from rcs... besides, system only returns 24 bits of exit
    # status... that's no good... so use open() and parse the output
    # to extract the status values.  Great that works, but I think
    # open() can still take a command list rather than a string, so
    # try to get that working.

    my($cmd) = "";
    foreach $item ( @sys_args ) {
	$cmd .= "$item ";
    }    

    open( PROCESS, "$cmd |" ) or die "Failed to open process: $cmd";

    my($status) = 0xdeadbeef;
    while ( <PROCESS> ) {
	print "\t| ", $_;
	if ( m/status 0x/ ) {
	    s/status //;
	    s/\n//;
	    $status = $_;
	}
    }
    close(PROCESS);

    $status;
}

######################################################################

# LoadLibrary - This test simply loads and unloads the COM library.
# It is executed by selecting the "load" test option in the config
# file.  It provides the means to quickly test that the
# MultiGentTestPaths, COM library paths, SysExecArgs, and geneneral
# network configuration, are all in working order.

sub LoadLibrary {
    my( $P, $V, $T, $F ) = @_;
    $status = 0;

    @args = ( $CFG{MultiGenTestPath}{$V}{$P},
	      "-r LoadLib $CFG{$V}{$P}",
	      "-r UnloadLib",
            );

    $status = ExecuteCommand( $P, @args );

    $status;
}

######################################################################

# CreateFile - Forms and executes a MultiGenTest command that creates a
# new file, executes the test to modify that file, and saves it.

sub CreateFile {
    my( $P, $V, $T, $F ) = @_;
    my($status) = 0;

    my(@args) = ( $CFG{MultiGenTestPath}{$V}{$P},
		  "-r LoadLib $CFG{$V}{$P}",
		  "-r FileOp write $CFG{SharedTestDirPath}{$P}/${F}",
		  "-r $CFG{$T}[1] ",
		  "-r FileOp save_and_close",
		  "-r UnloadLib",
		  );

    my($status) = ExecuteCommand( $P, @args );

    $status;
}

######################################################################

# ModifyFile - Forms and executes a MultiGenTest command that opens an
# existing and executes a test to modify it, and saves the file.

sub ModifyFile {
    my( $P, $V, $T, $F ) = @_;
    my($status) = 0;

    my(@args) = ( $CFG{MultiGenTestPath}{$V}{$P},
		  "-r LoadLib $CFG{$V}{$P}",
		  "-r FileOp modify $CFG{SharedTestDirPath}{$P}/${F}",
		  "-r $CFG{$T}[1] ",
		  "-r FileOp save_and_close",
		  "-r UnloadLib",
		  );

    my($status) = ExecuteCommand( $P, @args );

    $status;
}

######################################################################

# VerifyFile - Forms and executes a MultiGenTest command that opens an
# existing file (read only), executes a test to verify the file
# contents, and closes it.

sub VerifyFile {
    my( $P, $V, $T, $F ) = @_;
    my($status) = 0;

    my(@args) = ( $CFG{MultiGenTestPath}{$V}{$P},
		  "-r LoadLib $CFG{$V}{$P}",
		  "-r FileOp read $CFG{SharedTestDirPath}{$P}/${F}",
		  "-r $CFG{$T}[2] ",
		  "-r FileOp close",
		  "-r UnloadLib",
		  );

    my($status) = ExecuteCommand( $P, @args );

    $status;
}

######################################################################

# Compare status value to zero.
# Exit if non-zero and ExistOnTestFailure CFG policy is true.

sub TestStatus {
    my( $status ) = @_;

    if ( oct( $status ) != 0 ) {
	printf "Non-zero status\: 0x\%08x.\n", oct($status);
	print "TEST FAILED.\n";
	$GlobalState{TestFailedCount} += 1;
	if ( $CFG{ExitOnTestFailure} eq "true" ) {
	    FinalReport();
	    exit(-1);
	} 
    }
    else {
	$GlobalState{TestPassedCount} += 1;
    }
}

######################################################################

# Execute CopyCommand on CopyHost to copy src to dst.

sub CopyFile {
    my( $src, $dst ) = @_;

    my($full_src) = "$CFG{SharedTestDirPath}{$CFG{CopyHost}}/${src}";    
    my($full_dst) = "$CFG{SharedTestDirPath}{$CFG{CopyHost}}/${dst}"; 

    my(@args) = ( @{$CFG{CopyCommand}},
		  $full_src,
		  $full_dst );

    ExecuteCommand( $CFG{CopyHost}, @args );
}

######################################################################

sub PrintConfigSummary {
    print "Configuration Summary:\n\n";

    print "Platforms: \n";
    foreach $platform ( @{$CFG{Platforms}} ) {
	print "$platform ";
    }
    print "\n\n";
    
    print "Versions: \n";
    foreach $version ( @{$CFG{Versions}} ) {
	print "$version ";
    }
    print "\n\n";
    
    print "Tests: \n";
    foreach $test ( @{$CFG{Tests}} ) {
	print "$test ";
    }
    print "\n\n";

    foreach $version ( @{$CFG{Versions}} ) {
	print "Version $version:\n";
	foreach $machine ( @{$CFG{Platforms}} ) {
	    print "\t$machine: $CFG{$version}{$machine}\n"
	    }
	print "\n";
    }
    
    print "MultiGenTestPath:\n";
    foreach $version ( @{$CFG{Versions}} ) {
        print "\tVersion: $version\n";
	foreach $platform ( @{$CFG{Platforms}} ) {
	    print "\t\t$platform: $CFG{MultiGenTestPath}{$version}{$platform}\n";
        }
    }
    print "\n";

    print "Exclusion Rules:\n";
    print "\tModify operations using version(s): ";
    foreach $version ( @{$CFG{Versions}} ) {
	if ( $CFG{NoModifySupport}{Versions}{$version}  eq "true" ) {
	    print "$version ";
	}
    }
    print "\n";
    print "\tModify operations if creator and modifier byte order differ: $CFG{NoModifySupport}{ByteOrder}\n";
    print "\n";

    foreach $test ( @{$CFG{Tests}} ) {
	print "Test $test:\n";
	print "\tOption               : $CFG{$test}[0]\n";
	print "\tCreate/Modify Command: $CFG{$test}[1]\n";
	print "\tVerify Command       : $CFG{$test}[2]\n";
	print "\tUses result of       : $CFG{$test}[3]\n";
	print "\n";
	
	if ( !( $CFG{$test}[0] eq "create" ||
		$CFG{$test}[0] eq "modify" ||
		$CFG{$test}[0] eq "load" ) ) {
	    die "Test option must be \"create\", \"modify\", or \"load\" in test: $T\n";
	}
    }

    print "\n\n";
}

######################################################################

sub ExecuteTests {

    print "Execution Log:\n\n";

    # Cp = Create Platform
    # Cv = Create Version
    # Mp = Modify Platform
    # Mv = Modify Version
    # T  = Test
    # Vp = Verify Platform
    # Vv = Verify Version

    # FIXME - Move each test implementation (i.e. load, create, modify, verify),
    # into separate subroutines.

    foreach $T ( @{$CFG{Tests}} ) {
	foreach $Cp ( @{$CFG{Platforms}} ) {
	    foreach $Cv ( @{$CFG{Versions}} ) {

		if ( $CFG{$T}[0] eq "load" ) {
		    print "load $Cv on $Cp\n";
		    $status = LoadLibrary( $Cp, $Cv, $T );
		    TestStatus( $status );
		    print "\n";
		    next;
		}
		elsif ( $CFG{$T}[0] eq "create" ) {
		    $filename = GenerateUniqueFilename( $Cp, $Cv, $T );
		    print "create $filename by running $T on $Cp using $Cv\n";
		    $status = CreateFile( $Cp, $Cv, $T, $filename );
		    TestStatus( $status );
		    print "\n";

		    # for all platforms and versions: verify result of the create operation
		    foreach $Vp ( @{$CFG{Platforms}} ) {
			foreach $Vv ( @{$CFG{Versions}} ) {
			    print "verify $filename by running $T on $Vp using $Vv\n";
			    $status = VerifyFile( $Vp, $Vv, $T, $filename );
			    TestStatus( $status );
			    print "\n";
			} #Vv
		    } #Vp

		}
		elsif ( $CFG{$T}[0] eq "modify" ) {

		    # for all platforms and versions: copy and modify
		    # the file created by the test referenced by the
		    # third argument in the modify test configuration
		    # list.

		    $filename = GenerateUniqueFilename( $Cp, $Cv, $CFG{$T}[3] );

		    foreach $Mp ( @{$CFG{Platforms}} ) {
			foreach $Mv ( @{$CFG{Versions}} ) {

			    $exclude = 0;

			    $modify_filename = GenerateUniqueFilename( $Mp, $Mv, $T );

			    print "copy $filename to $modify_filename and ...\n";
			    print "modify $modify_filename by running $T on $Mp using $Mv\n";

			    # Exclusion Processing:

			    if ( $CFG{NoModifySupport}{Versions}{$Mv} eq "true" ) {
				print "Excluded: $Mv does not support modify operations.\n\n";
				$exclude = 1;
			    }  
			    elsif ( $CFG{NoModifySupport}{ByteOrder} eq "true" &&
				    $CFG{ByteOrder}{$Cp} ne $CFG{ByteOrder}{$Mp} ) {
				print "Excluded: $Cp and $Mp byte order mismatch;\n\n";
				$exclude = 1;
			    }

			    if ( $exclude == 1 ) {
			      $GlobalState{TestExcludedCount} += 1;
			    }
			    else {
			      CopyFile( $filename, $modify_filename );

			      $status = ModifyFile( $Mp, $Mv, $T, $modify_filename );
			      TestStatus( $status );
			      print "\n";
			    }

			    # for all platforms and versions: verify result of the modify operation
			    foreach $Vp ( @{$CFG{Platforms}} ) {
				foreach $Vv ( @{$CFG{Versions}} ) {

				    if ( $exclude == 1 ) {
					print "verify $modify_filename by running $T on $Mp using $Mv\n";
					print "Excluded: create or modify test was excluded.\n\n";
					$GlobalState{TestExcludedCount} += 1;
				    }
				    else {
					print "verify $modify_filename by running $T on $Mp using $Mv\n";
					$status = VerifyFile( $Mp, $Mv, $T, $modify_filename );
					TestStatus( $status );
					print "\n";
				    }

				} #Vv
			    } #Vp

			} #Mv
		    } #Mp
		}
		else {
		    # This is also tested in the summary code.  Repeat here just
		    # in case that is ever removed.
		    die "Test option must be \"create\", \"modify\" or \"load\" in test: $T\n";
		}

	    } #T
	} #Cv
    } #Cp
}

######################################################################

sub FinalReport {

    print "\nFinal Test Report:\n\n";

    printf "\t  Passed: %6d\n", $GlobalState{TestPassedCount};
    printf "\t  Failed: %6d\n", $GlobalState{TestFailedCount};
    printf "\tExcluded: %6d\n", $GlobalState{TestExcludedCount};
    printf "\t   Total: %6d\n\n", $GlobalState{TestPassedCount} +
	                         $GlobalState{TestFailedCount}  +
 			         $GlobalState{TestExcludedCount};
}

######################################################################

sub main {

    # Load the config file
    if ( $#ARGV < 0 ) {
	usage();
    }
    do $ARGV[0];

    InitGlobalState();

    PrintConfigSummary();

    ExecuteTests();

    FinalReport();

    exit(0);   
}

main();

# END
