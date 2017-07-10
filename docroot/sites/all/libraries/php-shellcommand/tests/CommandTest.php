<?php
use mikehaertl\shellcommand\Command;

class CommandTest extends \PHPUnit_Framework_TestCase
{
    // Create command from command string
    public function testCanPassCommandStringToConstructor()
    {
        $command = new Command('/bin/ls -l');

        $this->assertEquals('/bin/ls -l', $command->getExecCommand());
    }
    public function testCanPassCommandOptionToConstructor()
    {
        $command = new Command(array(
            'command' => '/bin/ls -l',
        ));

        $this->assertEquals('/bin/ls -l', $command->getExecCommand());
    }
    public function testCanSetCommand()
    {
        $command = new Command();
        $command->setCommand('/bin/ls -l');

        $this->assertEquals('/bin/ls -l', $command->getExecCommand());
    }

    // Options
    public function testCanSetOptions()
    {
        $command = new Command;
        $command->setOptions(array(
            'command' => 'echo',
            'escapeArgs' => false,
            'procEnv' => array('TESTVAR' => 'test'),
            'args' => '-n $TESTVAR',
        ));
        $this->assertEquals('echo -n $TESTVAR', $command->getExecCommand());
        $this->assertFalse($command->escapeArgs);
        $this->assertFalse($command->getExecuted());
        $this->assertTrue($command->execute());
        $this->assertTrue($command->getExecuted());
        $this->assertEquals('test', $command->getOutput());
    }
    public function testCanPassOptionsToConstructor()
    {
        $command = new Command(array(
            'command' => 'echo',
            'args' => '-n $TESTVAR',
            'escapeArgs' => false,
            'procEnv' => array('TESTVAR' => 'test'),
        ));
        $this->assertEquals('echo -n $TESTVAR', $command->getExecCommand());
        $this->assertFalse($command->escapeArgs);
        $this->assertFalse($command->getExecuted());
        $this->assertTrue($command->execute());
        $this->assertTrue($command->getExecuted());
        $this->assertEquals('test', $command->getOutput());
    }


    // Arguments
    public function testCanAddArguments()
    {
        $command = new Command();
        $command->setArgs('--arg1=x');
        $command->addArg('--a');
        $command->addArg('--a', 'v');
        $command->addArg('--a', array("v'1",'v2','v3'));
        $command->addArg('-b=','v', false);
        $command->addArg('-b=', array('v4','v5','v6'));
        $command->addArg('-c', '');
        $command->addArg('some name', null, true);
        $this->assertEquals("--arg1=x --a --a 'v' --a 'v'\''1' 'v2' 'v3' -b=v -b='v4' 'v5' 'v6' -c '' 'some name'", $command->getArgs());
    }
    public function testCanResetArguments()
    {
        $command = new Command();
        $command->addArg('--demo');
        $command->addArg('-name=test');
        $command->setArgs('--arg1=x');
        $this->assertEquals("--arg1=x", $command->getArgs());
    }
    public function testCanDisableEscaping()
    {
        $command = new Command();
        $command->escapeArgs = false;
        $command->addArg('--a');
        $command->addArg('--a', 'v');
        $command->addArg('--a', array("v1",'v2','v3'));
        $command->addArg('-b=','v', true);
        $command->addArg('-b=', array('v4','v5','v6'));
        $command->addArg('some name', null, true);
        $this->assertEquals("--a --a v --a v1 v2 v3 -b='v' -b=v4 v5 v6 'some name'", $command->getArgs());
    }
    public function testCanRunCommandWithArguments()
    {
        $command = new Command('ls');
        $command->addArg('-l');
        $command->addArg('-n');
        $this->assertEquals("ls -l -n", $command->getExecCommand());
        $this->assertFalse($command->getExecuted());
        $this->assertTrue($command->execute());
        $this->assertTrue($command->getExecuted());
    }

    // Output / error / exit code
    public function testCanRunValidCommand()
    {
        $dir = __DIR__;
        $command = new Command("/bin/ls $dir");

        $this->assertFalse($command->getExecuted());
        $this->assertTrue($command->execute());
        $this->assertTrue($command->getExecuted());
        $this->assertEquals("CommandTest.php\n", $command->getOutput());
        $this->assertEmpty($command->getError());
        $this->assertEmpty($command->getStdErr());
        $this->assertEquals(0, $command->getExitCode());
    }
    public function testCanNotRunEmptyCommand()
    {
        $command = new Command('/does/not/exist');
        $this->assertFalse($command->execute());
    }
    public function testCanNotRunNotExistantCommand()
    {
        $command = new Command('/does/not/exist');
        $this->assertFalse($command->getExecuted());
        $this->assertFalse($command->execute());
        $this->assertFalse($command->getExecuted());
        $this->assertNotEmpty($command->getError());
        $this->assertNotEmpty($command->getStdErr());
        $this->assertEmpty($command->getOutput());
        $this->assertEquals(127, $command->getExitCode());
    }
    public function testCanNotRunInvalidCommand()
    {
        $command = new Command('ls --this-does-not-exist');
        $this->assertFalse($command->getExecuted());
        $this->assertFalse($command->execute());
        $this->assertFalse($command->getExecuted());
        $this->assertNotEmpty($command->getError());
        $this->assertNotEmpty($command->getStdErr());
        $this->assertEmpty($command->getOutput());
        $this->assertEquals(2, $command->getExitCode());
    }
    public function testCanCastToString()
    {
        $command = new Command('ls');
        $command->addArg('-l');
        $command->addArg('-n');
        $this->assertEquals("ls -l -n", (string)$command);
    }

    // Proc
    public function testCanProvideProcEnvVars()
    {
        $command = new Command('echo $TESTVAR');
        $command->procEnv = array('TESTVAR' => 'testvalue');
        $this->assertTrue($command->execute());
        $this->assertEquals("testvalue\n", $command->getOutput());
    }
    public function testCanProvideProcDir()
    {
        $tmpDir = sys_get_temp_dir();
        $command = new Command('pwd');
        $command->procCwd = $tmpDir;
        $this->assertFalse($command->getExecuted());
        $this->assertTrue($command->execute());
        $this->assertTrue($command->getExecuted());
        $this->assertEquals($tmpDir."\n", $command->getOutput());
    }
}
