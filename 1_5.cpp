union example {
    int a[5];
    char b;
    double c;
};
struct example {
    int a[5];
    char b;
    double c;
} test_struct;
struct example {
    char b;
    double c;
    int a;
} test_struct;
int result = sizeof(example); /* 如果以最长20字节为准，内部double占8字节，这段内存的地址0x00000020并不是double的整数倍，只有当最小为0x00000024时可以满足整除double（8Byte）同时又可以容纳int
                                 a[5]的大小，所以正确的结果应该是result=24 */
struct example {
    int a[5];
    char b;
    double c;
} test_struct;
int result =
    sizeof(test_struct); /* 如果我们不考虑字节对齐，那么内存地址0x0021不是double（8Byte）的整数倍，所以需要字节对齐，那么此时满足是double（8Byte）的整数倍的最小整数是0x0024，说明此时char
                            b对齐int扩充了三个字节。所以最后的结果是result=32 */
struct example {
    char b;
    double c;
    int a;
} test_struct;
int result = sizeof(test_struct); /* 字节对齐除了内存起始地址要是数据类型的整数倍以外，还要满足一个条件，那就是占用的内存空间大小需要是结构体中占用最大内存空间的类型的整数倍，所以20不是double（8Byte）的整数倍，我们还要扩充四个字节，最后的结果是result=24
                                   */