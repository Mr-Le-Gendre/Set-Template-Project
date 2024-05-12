#ifndef H_unorderedSetType
#define H_unorderedSetType

#include "unorderedArrayListType.h"

template <class elemType>
class unorderedSetType : public unorderedArrayListType<elemType> {
public:
    void insertAt(int location, const elemType& insertItem) override {
        if (this->seqSearch(insertItem) == -1)
            unorderedArrayListType<elemType>::insertAt(location, insertItem);
        else
            cout << "Item already in the set." << endl;
    }

    void insertEnd(const elemType& insertItem) override {
        if (this->seqSearch(insertItem) == -1)
            unorderedArrayListType<elemType>::insertEnd(insertItem);
        else
            cout << "Item already in the set." << endl;
    }

    void replaceAt(int location, const elemType& repItem) override {
        if (this->seqSearch(repItem) == -1)
            unorderedArrayListType<elemType>::replaceAt(location, repItem);
        else
            cout << "Item already in the set." << endl;
    }

    unorderedSetType operator+(const unorderedSetType& otherSet) {
        unorderedSetType<elemType> unionSet;

        for (int i = 0; i < this->listSize(); i++)
            unionSet.insertEnd(this->list[i]);

        for (int i = 0; i < otherSet.listSize(); i++)
            unionSet.insertEnd(otherSet.list[i]);

        return unionSet;
    }

    unorderedSetType operator-(const unorderedSetType& otherSet) {
        unorderedSetType<elemType> intersectSet;

        for (int i = 0; i < this->listSize(); i++)
            if (otherSet.seqSearch(this->list[i]) != -1)
                intersectSet.insertEnd(this->list[i]);

        return intersectSet;
    }

    unorderedSetType(int size = 100)
        : unorderedArrayListType<elemType>(size) {}
};

#endif // H_unorderedSetType
