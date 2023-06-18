#ifndef CONTACT_MANAGEMENT_CONTACT_H
#define CONTACT_MANAGEMENT_CONTACT_H

#endif //CONTACT_MANAGEMENT_CONTACT_H

// 名字最大长度
#define MAX_NAME_LENGTH 10
// 性别最大长度
#define MAX_GENDER_LENGTH 5
// 电话最大长度
#define MAX_PHONE_LENGTH 20
// 地址最大长度
#define MAX_ADDRESS_LENGTH 100
// 通讯录默认大小
#define DEFAULT_CONTACT_SIZE 5

// 菜单的操作类型
enum OPERATION {
    EXIT,
    ADD,
    DELETE,
    SEARCH,
    UPDATE,
    SHOW,
    SORT,
    SAVE,
    CLEAR
};

// 用户结构体
struct user {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[MAX_GENDER_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
};

// 通讯录
struct contact {
    // 用户信息
    struct user* user;
    // 记录当前已有元素个数
    int size;
    // 当前通讯录最大容量
    int capacity;
};

/**
 * 初始化通讯录
 * @param contact
 */
void init(struct contact* contact);

/**
 * 添加联系人
 * @param contact
 */
void add(struct contact* contact);

/**
 * 打印联系人
 * @param contact
 */
void show(const struct contact* contact);

/**
 * 删除联系人
 * @param contact
 */
void delete(struct contact* contact);

/**
 * 搜索联系人
 * @param contact
 */
void search(const struct contact* contact);

/**
 * 更新联系人
 * @param contact
 */
void update(struct contact* contact);

/**
 * 按姓名排序
 * @param contact
 */
void sort(struct contact* contact);

/**
 * 释放动态开辟的内存
 * @param contact
 */
void destroy(struct contact* contact);

/**
 * 保存通讯录
 * @param contact
 */
void save(struct contact* contact);

/**
 * 从文件中加载通讯录
 * @param contact
 */
void load(struct contact* contact);

/**
 * 清除通讯录
 * @param contact
 */
void clear(struct contact* contact);