//一个类有它的访问者，它的访问者一般要访问这个类的类方法，类成员等等。
//于是乎，就可以将访问一个类的类成员和类方法的一系列操作封装到一个类中，这个类就是访问者类。
//然后给被访问类中留一个访问者的接收接口，就可以直接通过类来接收访问者

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class PoseDesigner;

class Poser {
public:
    virtual void ShowPose() = 0;
    virtual void KeepPose() = 0;
    virtual void ChangePose() = 0;
    virtual void accept(PoseDesigner* designer) = 0;
};

class PoserA : public Poser {
public:
    void ShowPose() override {
        cout << "A run pose" << endl;
    }
    void KeepPose() override {
        cout << "A keep pose" << endl;
    }
    void ChangePose() override {
        cout << "A change pose" << endl;
    }

    void accept(PoseDesigner* designer){
        designer->DesignPose(this);
    }
};

class PoserB : public Poser {
public:
    void ShowPose() override {
        cout << "B run pose" << endl;
    }
    void KeepPose() override {
        cout << "B keep pose" << endl;
    }
    void ChangePose() override {
        cout << "B change pose" << endl;
    } 
    void accept(PoseDesigner* designer){
        designer->DesignPose(this);
    }  
};  


class PoseDesigner {
public:
    virtual void DesignPose(Poser* poser) = 0;
    virtual ~PoseDesigner() = default;
};  

class PoseDesignerA : public PoseDesigner {
public:
    void DesignPose(Poser* poser) override {
        poser->ShowPose();
        poser->KeepPose();
    }
};  

class PoseDesignerB : public PoseDesigner {
public:
    void DesignPose(Poser* poser) override {
        poser->ShowPose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->KeepPose();
    }
};  

class PoseDesignerC : public PoseDesigner {         
public:
    void DesignPose(Poser* poser) override {
        poser->ShowPose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
        poser->ChangePose();
    }
};

class Place {
public:
    vector<Poser*> posers;
    void AddPoser(Poser* poser) {
        posers.push_back(poser);
    }
    void RemovePoser(Poser* poser) {
        for (int i = 0; i < posers.size(); i++) {
            if (posers[i] == poser) {
                posers.erase(posers.begin() + i);
            }
        }
    }
    void accept(PoseDesigner* designer){
        for (int i = 0; i < posers.size(); i++) {
            posers[i]->accept(designer);
        }
    }
};

int main() {
    Place place;
    PoserA poserA;
    PoserB poserB;
    place.AddPoser(&poserA);
    place.AddPoser(&poserB);
    PoseDesignerA designerA;
    PoseDesignerB designerB;
    PoseDesignerC designerC;
    place.accept(&designerA);
    place.accept(&designerB);
    place.accept(&designerC);
    return 0;
}       