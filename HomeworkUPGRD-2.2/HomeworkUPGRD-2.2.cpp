
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

    void set_num(smart_array smarr) {
        int arrsize = sizeof(smarr.arr) / sizeof(smarr.arr[0]);
        if (arrsize > actual_size) {
            for (int i = 0; i < logical_size; i++) {
                arr[i] = smarr.get_element(i);
            }
            for (int i = logical_size; i < actual_size; i++) {
                add_element(smarr.get_element(i));
            }
        }
        else {
            for (int i = 0; i < arrsize; i++) {
                arr[i] = smarr.get_element(i);
            }
        }
    }

    ~smart_array() {
        delete[]arr;

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

        arr.set_num(arr2);
    }
    catch (const exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}