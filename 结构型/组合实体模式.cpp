//组合实体模式，就是构建一个树形结构，树形结构中的每个节点都是一个组合实体，组合实体中包含一个或者多个实体，实体可以是组合实体，也可以是叶子实体。
//然后可以使用递归的方式来管理整个实体结构

//以文件夹和文件为例子，来构建这样一个实体组合模式

#include <iostream>
#include <vector>
#include <string>  
using namespace std;

class fileSystemComponent
{
public:
    std::string name;
    std::string path;
    fileSystemComponent* parent;
    std::vector<fileSystemComponent*> children;
public:
    fileSystemComponent(std::string name, std::string path, fileSystemComponent* parent)
    {
        this->name = name;
        this->path = path;
        this->parent = parent;
        this->children = {};
    }
    virtual void add(fileSystemComponent* component){};
    virtual void remove(fileSystemComponent* component){};
    virtual void display(int depth) = 0;
};

class file : public fileSystemComponent
{
public:
    file(std::string name, std::string path, fileSystemComponent* parent) : fileSystemComponent(name, path, parent) {}
    virtual void display(int depth) override
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "  ";
        }
        cout << name << endl;
    }
};

class folder : public fileSystemComponent  
{
public:
    folder(std::string name, std::string path, fileSystemComponent* parent) : fileSystemComponent(name, path, parent) {}
    virtual void add(fileSystemComponent* component) override
    {
        component->parent = this;
        children.push_back(component);
    }
    virtual void remove(fileSystemComponent* component) override
    {
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i] == component)
            {
                children.erase(children.begin() + i);
                break;
            }
        }
    }
    virtual void display(int depth) override
    {
        for (int i = 0; i < depth; i++)
        {
            cout << "  ";
        }
        cout << name << endl;
        for (int i = 0; i < children.size(); i++)
        {
            children[i]->display(depth + 1);
        }
    }
    ~folder()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }   
};

int main()
{
    fileSystemComponent* root = new folder("root", "/", nullptr);
    fileSystemComponent* home = new folder("home", "/home", root);
    fileSystemComponent* user = new folder("user", "/home/user", home);
    fileSystemComponent* file1 = new file("file1", "/home/user/file1", user);
    fileSystemComponent* file2 = new file("file2", "/home/user/file2", user);
    fileSystemComponent* file3 = new file("file3", "/home/user/file3", user);
    fileSystemComponent* bin = new folder("bin", "/bin", root);
    fileSystemComponent* file4 = new file("file4", "/bin/file4", bin);
    fileSystemComponent* file5 = new file("file5", "/bin/file5", bin);
    root->add(home);
    root->add(bin);
    home->add(user);
    user->add(file1);
    user->add(file2);
    user->add(file3);
    bin->add(file4);
    bin->add(file5);
    root->display(0);
    return 0;
}
