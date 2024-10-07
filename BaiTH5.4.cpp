#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class Borrowable {
public:
    virtual void borrow() = 0;
    virtual void returnItem() = 0;
    virtual bool isAvailable() const = 0;
    virtual std::string getTitle() const = 0;
    virtual std::string getAuthor() const = 0;
    virtual std::string getISBN() const = 0;
    virtual ~Borrowable() = default;
};

class Book : public Borrowable {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

public:
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), available(true) {}

    void borrow() override {
        if (available) {
            available = false;
            std::cout << "Sach '" << title << "' da duoc muon." << std::endl;
        }
        else {
            std::cout << "Sach '" << title << "' khong co san de muon." << std::endl;
        }
    }

    void returnItem() override {
        available = true;
        std::cout << "Sach '" << title << "' da duoc tra lai." << std::endl;
    }

    bool isAvailable() const override {
        return available;
    }

    std::string getTitle() const override {
        return title;
    }

    std::string getAuthor() const override {
        return author;
    }

    std::string getISBN() const override {
        return ISBN;
    }
};

class Library {
private:
    std::map<std::string, std::unique_ptr<Borrowable>> items;

public:
    void addItem(std::unique_ptr<Borrowable> item) {
        items[item->getTitle()] = std::move(item);
    }

    void borrowItem(const std::string& title) {
        auto it = items.find(title);
        if (it != items.end()) {
            it->second->borrow();
        }
        else {
            std::cout << "Khong tim thay sach '" << title << "' trong thu vien." << std::endl;
        }
    }

    void returnItem(const std::string& title) {
        auto it = items.find(title);
        if (it != items.end()) {
            it->second->returnItem();
        }
        else {
            std::cout << "Khong tim thay sach '" << title << "' trong thu vien de tra." << std::endl;
        }
    }

    // Ham tim kiem sach theo tu khoa
    std::vector<Borrowable*> searchBooks(const std::string& keyword) {
        std::vector<Borrowable*> results;
        for (const auto& pair : items) {
            if (pair.second->getTitle().find(keyword) != std::string::npos ||
                pair.second->getAuthor().find(keyword) != std::string::npos ||
                pair.second->getISBN().find(keyword) != std::string::npos) {
                results.push_back(pair.second.get());
            }
        }
        return results;
    }
};

int main() {
    Library library;

    // Them mot so sach vao thu vien
    library.addItem(std::make_unique<Book>("C++ Programming", "Author A", "ISBN001"));
    library.addItem(std::make_unique<Book>("Effective C++", "Author B", "ISBN002"));
    library.addItem(std::make_unique<Book>("Learning C++", "Author C", "ISBN003"));

    // Muon sach
    library.borrowItem("C++ Programming");
    library.borrowItem("Effective C++");

    // Tra sach
    library.returnItem("C++ Programming");

    // Tim kiem sach
    auto results = library.searchBooks("C++");
    std::cout << "Ket qua tim kiem cho 'C++':" << std::endl;
    for (Borrowable* book : results) {
        std::cout << book->getTitle() << " - Tac gia: " << book->getAuthor() << std::endl;
    }

    return 0;
}

