#include <assert.h>

const int defaultSize = 10;

//ADT
template <typename E> class List {
private:
    void operator =(const List&); //assign protect
    List(const List&); //copy protect
public:
    List() {}; //default constructor
    virtual ~List(); //default destructor

    //clear the contents of the list
    virtual void clear() = 0;
    //insert the special item
    //item: the element to insert
    virtual void insert(const E& item) = 0;
    //append an element in the end of the list
    //item: the element to append
    virtual void append(const E& item) = 0;
    //remove and return the current element
    virtual E remove() = 0;
    //move to the start element
    virtual void moveToStart() = 0;
    //move to the end element
    virtual void moveToEnd() = 0;
    //move to the previous element
    //if the current element is at the beginning, then nothing to do
    virtual void prev() = 0;
    //move to the next element
    //if the current element is at the end, then nothing to do
    virtual void next() = 0;
    //get the length of the list
    virtual int length() const = 0;
    //get the position of the current element in the list
    virtual int currPos() const = 0;
    //move to the position
    virtual void movToPos(const int Pos) = 0;
    //return the current element
    virtual const E& getValue() const = 0;
};

//Array-Based list
template <typename E>
class AList{
private:
    //the max size of the list
    int maxSize;
    //the size of the list
    int listSize;
    //position of the current element
    int curr;
    E* listArray;
public:
    //constructor
    AList(int size = defaultSize): maxSize(size) {
        listSize = curr = 0;
        listArray = new E[maxSize];
    };
    //destructor
    ~AList() {
        delete [] listArray;
    }
    //clear function: delete the array and rebuild one
    void clear() {
        delete [] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    //insert function: shift up the elements after the current element and the current element to make room
    void insert(const E& item) {
        //Assert(listSize < maxSize);
        //march down the elements list after the current element and shift elements up to make room
        for(int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = item;
        listSize++;
    }
    //append function: assign the tail element to the insert element and increase the listSize
    void append(const E& item) {
        //Assert(listSize < maxSize, "List Capacity Exceeded!");
        listArray[listSize++] = item;
    }
    //remove function: save the current element temporarily and return it
    //shift down the element after the current element to cover the current element and decree the listSize
    E remove() {
        //Assert((curr >= 0) && (curr < listSize), "No Element");
        E currEle = listArray[curr];
        for(int i = curr; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return currEle;
    }
    //moveToStart function: assign 0 to curr
    void moveToStart() {
        curr = 0;
    }
    //moveToEnd function: assign listsize-1 to curr
    void moveToEnd() {
        curr = listSize - 1;
    }
    //moveToPos function: assign the parameter to curr
    void moveToPos(const int Pos) {
        //Assert((Pos > 0) && (Pos < listSize), "Position Out of Range!");
        curr = Pos;
    }
    //prev function: curr-1, if curr = 0, then nothing to do
    void prev() {
        if(curr != 0) {
            curr--;
        }
    }
    //next function: curr + 1, if curr = listSize-1, then nothing to do
    void next() {
        if(curr < listSize) {
            curr++;
        }
    }
    //length function: return the listSize
    int length() const {
        return listSize;
    }
    //currPos function: return curr
    int currPos() {
        return curr;
    }
    //
    const E& getValue() const {
        //Assert((curr > 0) && (curr < listSize), "No Current Element");
        return listArray[curr];
    }
};
