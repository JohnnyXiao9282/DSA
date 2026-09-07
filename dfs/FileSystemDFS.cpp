#include <iostream>
#include <string>
#include <vector>

class Entry {
public:
    std::string name;

    Entry(const std::string& name) : name(name) {}
    virtual ~Entry() {}

    virtual bool isFolder() const = 0;
};

class File : public Entry {
public:
    File(const std::string& name) : Entry(name) {}

    bool isFolder() const override {
        return false;
    }
};

class Folder : public Entry {
public:
    std::vector<Entry*> children;

    Folder(const std::string& name) : Entry(name) {}

    bool isFolder() const override {
        return true;
    }

    void add(Entry* child) {
        children.push_back(child);
    }
};

void dfs(Entry* node, int depth = 0) {
    std::cout << std::string(depth * 2, ' ') << node->name
               << (node->isFolder() ? "/" : "") << std::endl;

    if (node->isFolder()) {
        Folder* folder = static_cast<Folder*>(node);
        for (Entry* child : folder->children) {
            dfs(child, depth + 1);
        }
    }
}

int main() {
    // root/
    //   a.txt
    //   src/
    //     main.cpp
    //     utils/
    //       helper.cpp
    //   README.md
    Folder* root = new Folder("root");
    Folder* src = new Folder("src");
    Folder* utils = new Folder("utils");

    root->add(new File("a.txt"));
    root->add(src);
    root->add(new File("README.md"));

    src->add(new File("main.cpp"));
    src->add(utils);

    utils->add(new File("helper.cpp"));

    dfs(root);

    return 0;
}
