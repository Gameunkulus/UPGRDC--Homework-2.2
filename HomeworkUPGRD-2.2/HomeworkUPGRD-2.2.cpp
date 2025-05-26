


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <cstdio>;
using namespace std;

class smart_array {
private:
    FILE* f;

public:

    int actual_size;
    int logical_size = 0;
    int* arr;

    smart_array(const string& filename) {
        f = fopen(filename.c_str(), "r");
        if (f == nullptr) {
            throw runtime_error("file open failed");
        }
        actual_size = 0;
    }

    void write(const std::string& str) {
        fprintf(f, str.c_str());
    }

    smart_array(int num) {
        actual_size = num;
        arr = new int[num];
        for (int i = 0; i < num; i++)
            arr[i] = 0;
    }

    void add_element(int num) {

        if (logical_size >= actual_size) {
            actual_size *= 2;
            int* newArr = new int[actual_size];
            for (int i = 0; i < logical_size; i++) {
                newArr[i] = arr[i];
            }
            *arr = *newArr;
            delete[] newArr;
        }
        arr[logical_size] = num;
        logical_size++;

    }

    void print_array() {
        cout << "Динамический массив: ";
        for (int i = 0; i < logical_size; i++) {
            cout << arr[i] << " ";
        }
        for (int i = logical_size; i < actual_size; i++) {
            cout << " _ ";
        }
    }

    int get_element(int num) {
        if (num > actual_size || num < 0) {
            throw exception("Данный номер отствутствует.");
        }
        return arr[num];
    }

    ~smart_array() {
        delete[]arr;
        fclose(f);
    }
};

int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array arr2(2);
        arr2.add_element(44);
        arr2.add_element(34);

        arr = arr2;
    }
    catch (const exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}