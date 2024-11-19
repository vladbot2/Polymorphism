#include <iostream>

using namespace std;

class FileHandler {
public:
    virtual void Display(const char* fileName) {
        FILE* file = fopen(fileName, "rb");
        if (!file) {
            cout << "Cannot open file: " << fileName << endl;
        }

        int value;
        while (fread(&value, sizeof(int), 1, file)) {
            cout << static_cast<char>(value);
        }
        cout << endl;
    }
};

class AsciiFileHandler : public FileHandler {
public:
    void Display(const char* fileName) override {
        FILE* file = fopen(fileName, "rb");
        if (!file) {
            cout << "Cannot open file: " << fileName << endl;
        }

        int value;
        while (fread(&value, sizeof(int), 1, file)) {
            cout << value << "_";
        }
        cout << endl;
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* fileName) override {
        FILE* file = fopen(fileName, "rb");
        if (!file) {
            cout << "Cannot open file: " << fileName << endl;
        }

        int value;
        while (fread(&value, sizeof(int), 1, file)) {
            for (int bit = 31; bit >= 0; --bit) {
                cout << ((value >> bit) & 1);
            }
            cout << " ";
        }
        cout << endl;
    }
};

int main() {
    const char* fileName = "example.txt";

    FileHandler baseHandler;
    baseHandler.Display(fileName);

    AsciiFileHandler asciiHandler;
    asciiHandler.Display(fileName);

    BinaryFileHandler binaryHandler;
    binaryHandler.Display(fileName);
}
