
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <cstdio>;
using namespace std;

class smart_array {
private:
    int actual_size;
    int logical_size = 0;
    int* arr;

public:

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
            throw exception("Данный номер отсутствует.");
        }
        return arr[num];
    }
    int get_actsize() {
        int actsize = actual_size;
        return actsize;
    }

    smart_array& operator=(smart_array& other){
        int arrsize = sizeof(other.get_actsize()) / sizeof(other.arr[0]);
        if (arrsize > get_actsize()) {
            for (int i = 0; i < logical_size; i++) {
                arr[i] = other.get_element(i);
            }
            for (int i = logical_size; i < actual_size; i++) {
                add_element(other.get_element(i));
            }
        }
        else {
            for (int i = 0; i < arrsize; i++) {
                arr[i] = other.get_element(i);
            }
        }
        return *this;
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
        cout << arr.get_element(0);
    }
    catch (const exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}