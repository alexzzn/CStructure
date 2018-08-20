#include <iostream>
using namespace std;

// 最大堆
template <typename Item> 
class MaxHeap {
    private:

        Item *data;
        int count;
        void shiftUp(int count) {

            while(data[count/2] < data[count]) {
                int temp = data[count/2];
                data[count/2] = data[count];
                data[count] = temp;
                count = count/2;
            }
        }
    public:

        MaxHeap(int capacity) {
            data = new Item[capacity+1];
            count = 0;
        }

        ~MaxHeap() {

            delete []data;
        }

        int size() {
            
            return count;
        }

        bool isEmpety() {
            return count == 0 ? true:false;
        }

        void insert(int k) {

            data[count+1] = k;
            count++;
            shiftUp(count);
        }
};

int main(int argc, char const *argv[])
{

    MaxHeap<int> *heap = new MaxHeap<int>(100);

    srand(time(NULL));
    for(int i=0;i<15;i++) {

        heap->insert(rand()/50);
    }
    cout<<heap->size();
    return 0;
}
