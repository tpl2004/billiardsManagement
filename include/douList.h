#pragma once
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
