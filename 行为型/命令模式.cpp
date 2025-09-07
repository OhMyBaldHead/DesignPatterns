//命令模式，就是把操作封装成一个命令，然后可以在这个命令中添加操作的回滚，日志等功能。

//设置一个电视类，有音量的上下，频道的更换，开关功能。将这些功能封装成为命令。

#include <iostream>
#include <string>
using namespace std;    

class TV {
public:
    bool isOn;
    int volume;
    int channel;
    void open() {
        cout << "open TV" << endl;
        isOn = true;
    }
    void close() {
        cout << "close TV" << endl;
        isOn = false;
    }
    void turnUp() {
        cout << "turn up TV" << endl;
        if(volume < 100) {volume++;}
    }
    void turnDown() {
        cout << "turn down TV" << endl;
        if(volume > 0) {
        volume--;
        }
    }
    void changeChannel(int chan) {
        cout << "change channel to " << chan << endl;
        channel = chan;
    }
    TV() {
        isOn = false;
        volume = 15;
        channel = 0;
    }   
};

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class ChangeLoveChannelCommand : public Command {
public:
    TV* tv;
    int oldChannel;
    ChangeLoveChannelCommand(TV* tv) {
        this->tv = tv;
    }
    void execute() override {
        int loveChannel = 100;
        oldChannel = tv->channel;
        tv->changeChannel(loveChannel);

    }
    void undo() override {
        tv->changeChannel(oldChannel);
    }
};

class UpVolumeCommand : public Command {
public:
    TV* tv;
    UpVolumeCommand(TV* tv) {
        this->tv = tv;
    }
    void execute() override {
        tv->turnUp();
    }
    void undo() override {
        tv->turnDown();
    }
};      

class DownVolumeCommand : public Command {
public:
    TV* tv; 
    DownVolumeCommand(TV* tv) {
        this->tv = tv;
    }
    void execute() override {
        tv->turnDown();
    }
    void undo() override {
        tv->turnUp();
    }
};      

class OpenCommand : public Command {
public:
    TV* tv;
    OpenCommand(TV* tv) {
        this->tv = tv;
    }
    void execute() override {
        tv->open();
    }
    void undo() override {
        tv->close();
    }
};   

class CloseCommand : public Command {
public:
    TV* tv;
    CloseCommand(TV* tv) {
        this->tv = tv;
    }
    void execute() override {
        tv->close();
    }
    void undo() override {
        tv->open();
    }
};      

int main(){
    TV tv;
    Command* openCommand = new OpenCommand(&tv);
    Command* closeCommand = new CloseCommand(&tv);
    Command* upVolumeCommand = new UpVolumeCommand(&tv);
    Command* downVolumeCommand = new DownVolumeCommand(&tv);
    Command* loveChannelCommand = new ChangeLoveChannelCommand(&tv);
    openCommand->execute();
    upVolumeCommand->execute();
    downVolumeCommand->execute();
    loveChannelCommand->execute();
    closeCommand->execute();
    upVolumeCommand->undo();
    downVolumeCommand->undo();
    loveChannelCommand->undo();
    closeCommand->undo();
    delete openCommand;
    delete closeCommand;
    delete upVolumeCommand;
    delete downVolumeCommand;
    delete loveChannelCommand;
    return 0;   
}
