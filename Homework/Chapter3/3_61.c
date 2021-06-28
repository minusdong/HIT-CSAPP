/*
 3.61题
 假如xp为空指针，对空指针 NULL 读数据的操作错误。
 */
long cread_alt(long *xp) {
    long temp = 0;
    long *p = xp ? xp : &temp;
    return *p;
}