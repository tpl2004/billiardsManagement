#pragma once
#include <iostream>
template<class T>
struct node {
    T data;
    node<T> *pre;
    node<T> *next;
};

template<class T>
struct douList {
    node<T> *head;
    node<T> *tail;

    /*ham khoi tao mac dinh.
    tat ca cac loai douList deu duoc khoi tao la danh sach rong.*/
    douList();

    /*ham tao node.*/
    static node<T> *createNode(const T &data);

    /*ham chen dau.*/
    static void insertFirst(douList<T> &L, const T &data);

    /*ham chen cuoi.*/
    static void insertLast(douList<T> &L, const T &data);

    /*ham chen o vi tri bat ki.
    vt0 (node0) vt1 (node1) vt2 (node2) vt3.
    NOTE: list rong => vt0(duy nhat).*/
    static void insert(douList<T> &L, const T &data, int pos);

    /*ham xoa dau.*/
    static void delFirst(douList<T> &L);

    /*ham xoa cuoi.*/
    static void delLast(douList<T> &L);

    /*ham xoa node bat ki.
    (node0) (node1) (node2) => pos = 0, 1, 2, ...*/
    static void del(douList<T> &L, int pos);

    /*ham tra ve so luong node co trong danh sach.*/
    static int size(const douList<T> &L);

    /*ham hien thi danh sach.
    # reverse=false(default): hien thi tu dau->cuoi
    # reverse=true: hien thi tu cuoi->dau*/
    static void show(const douList<T> &L, bool reverse=false);
};

template<class T>
douList<T>::douList() {
    head = NULL;
    tail = NULL;
}

template<class T>
node<T> * douList<T>::createNode(const T &data) {
    node<T> *tmp = new node<T>;
    tmp->data = data;
    tmp->pre = NULL;
    tmp->next = NULL;
    return tmp;
}

template<class T>
void douList<T>::insertFirst(douList<T> &L, const T &data) {
    node<T> *tmp = douList<T>::createNode(data);
    if(L.head == NULL) {
        L.head = tmp;
        L.tail = tmp;
        return;
    }
    L.head->pre = tmp;
    tmp->next = L.head;
    L.head = tmp;
}

template<class T>
void douList<T>::insertLast(douList<T> &L, const T &data) {
    node<T> *tmp = douList<T>::createNode(data);
    if(L.head == NULL) {
        L.head = tmp;
        L.tail = tmp;
        return;
    }
    L.tail->next = tmp;
    tmp->pre = L.tail;
    L.tail = tmp;
}

template<class T>
void douList<T>::insert(douList<T> &L, const T &data, int pos) {
    int SIZE = douList<T>::size(L);
    if(pos < 0 or pos > SIZE) return;
    if(pos == 0) douList<T>::insertFirst(L, data);
    else if(pos == SIZE) douList<T>::insertLast(L, data);
    else {
        node<T> *tmp = douList<T>::createNode(data);
        node<T> *node_pre_pos = L.head;
        for(int i = 1; i <= pos-1; i++) {
             node_pre_pos = node_pre_pos->next;
        }
        node<T> *node_beh_pos = node_pre_pos->next;
        node_pre_pos->next = tmp;
        node_beh_pos->pre = tmp;
        tmp->pre = node_pre_pos;
        tmp->next = node_beh_pos;
    }
}

template<class T>
void douList<T>::delFirst(douList<T> &L) {
    if(L.head == NULL) return;
    node<T> *next_head_node = L.head->next;
    (next_head_node == NULL)? L.tail = NULL : next_head_node->pre = NULL;
    delete L.head;
    L.head = next_head_node;
}

template<class T>
void douList<T>::delLast(douList<T> &L) {
    if(L.head == NULL) return;
    node<T> *pre_tail_node = L.tail->pre;
    (pre_tail_node == NULL)? L.head = NULL : pre_tail_node->next = NULL;
    delete L.tail;
    L.tail = pre_tail_node;
}

template<class T>
void douList<T>::del(douList<T> &L, int pos) {
    int SIZE = douList<T>::size(L);
    if(pos < 0 or pos >= SIZE) return;
    if(pos == 0) douList<T>::delFirst(L);
    else if(pos == SIZE-1) douList<T>::delLast(L);
    else {
        node<T> *del_node = L.head;
        for(int i = 1; i <= pos; i++) {
            del_node = del_node->next;
        }
        node<T> *pre_del_node = del_node->pre;
        node<T> *next_del_node = del_node->next;
        delete del_node;
        pre_del_node->next = next_del_node;
        next_del_node->pre = pre_del_node;
    }
}

template<class T>
int douList<T>::size(const douList<T> &L) {
    int SIZE = 0;
    node<T> *tmp = L.head;
    while(tmp != NULL) {
        SIZE++;
        tmp = tmp->next;
    }
    return SIZE;
}

template<class T>
void douList<T>::show(const douList<T> &L, bool reverse) {
    node<T> *tmp = (reverse? L.tail : L.head);
    while(tmp != NULL) {
        //std::cout << tmp->data << " ";
        tmp->data.show();
        reverse? tmp = tmp->pre : tmp = tmp->next;
    }
}
