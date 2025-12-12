// #pragma once
// #include<iostream>
// #include<string>
// #include<fstream>
// using namespace std;
// #define FILENAME "empFile.txt"

// //职工类
// class Worker
// {
//     public:
//         //职工编号
//         int m_Id;
//         //职工姓名
//         string m_Name;
//         //部门编号
//         int m_DeptId;

//         //显示个人信息
//         virtual void showInfo()=0;
//         //获取岗位名称
//         virtual string getDeptId()=0;
// };

// //职工管理类
// class workManager
// {
//     public:
//         //职工人数
//         int m_EmpNum;
//         //职工数组指针
//         Worker ** worker;
//         //判断文件是否为空
//         bool fileIsEmpty;

//         //构造函数
//         workManager();

//         //展示菜单
//         void showMenu();

//         //退出系统
//         void exitSystem();

//         //增加职工
//         void addEmp();

//         //保存文件
//         void save();

//         //获取文件中的职工人数
//         int getEmpNum();

//         //初始化职工
//         void initEmp();

//         //显示职工
//         void showEmp();

//         //判断职工是否存在
//         int isExist(int id);
//         //删除职工
//         void delEmp();

//         //修改职工
//         void modEmp();

//         //查找职工
//         void findEmp();

//         //按照编号排序
//         void sortEmp();

//         //清空所有文档
//         void cleanFile();

//         //析构函数
//         ~workManager();

// };

// //普通员工类
// class Employee:public Worker
// {
//     public:
//         //构造函数
//         Employee(int id,string name,int dId);
//         //显示个人信息
//         virtual void showInfo();
//         //获取岗位名称
//         virtual string getDeptId();
// };

// //经理类
// class Manager:public Worker
// {
//     public:
//         //构造函数
//         Manager(int id,string name,int dId);
//         //显示个人信息
//         virtual void showInfo();
//         //获取岗位名称
//         virtual string getDeptId();
// };

// //老板类
// class Boss:public Worker
// {
//     public:
//         //构造函数
//         Boss(int id,string name,int dId);
//         //显示个人信息
//         virtual void showInfo();
//         //获取岗位名称
//         virtual string getDeptId();
// };