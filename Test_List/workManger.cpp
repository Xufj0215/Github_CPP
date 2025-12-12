

// //#include<iostream>
// #include"workManger.h"
// using namespace std;

// //职工管理类构造函数
// workManager::workManager()
// {
//     //1.文件不存在
//     ifstream ifs;
//     ifs.open(FILENAME,ios::in);
//     if(!ifs.is_open())
//     {
//         cout<<"文件不存在"<<endl;
//         //初始化属性
//         //初始化职工人数
//         this->m_EmpNum=0;
//         //初始化职工数组指针
//         this->worker=NULL;
//         //初始化文件是否为空
//         this->fileIsEmpty=true;
//         //关闭文件
//         ifs.close();
//         return;
//     }
//     //2.文件存在，数据为空
//     char ch;
//     ifs>>ch;
//     if(ifs.eof())
//     {
//         cout<<"文件为空"<<endl;
//         //初始化职工人数
//         this->m_EmpNum=0;
//         //初始化职工数组指针
//         this->worker=NULL;
//         //初始化文件是否为空
//         this->fileIsEmpty=true;
//         //关闭文件
//         ifs.close();
//         return;
//     }
//     //3.文件存在且记录数据
//     int num=this->getEmpNum();
//     //cout<<"职工人数为："<<num<<endl;
//     this->m_EmpNum=num;
//     //开辟空间
//     this->worker=new Worker*[this->m_EmpNum];
//     //初始化职工
//     this->initEmp();
//     //文件不为空
//     this->fileIsEmpty=false;
//     //cout<<"职工信息读取成功"<<endl;
//     // for(int i=0;i<this->m_EmpNum;i++)
//     // {
//     //     cout<<"职工编号："<<this->worker[i]->m_Id
//     //         <<"\t职工姓名:"<<this->worker[i]->m_Name
//     //         <<"\t岗位:"<<this->worker[i]->getDeptId()
//     //         <<"\t岗位职责:"<<this->worker[i]->getDeptId()<<endl;
//     // }
//     //关闭文件
//     ifs.close();
// }

// //获取文件中的职工人数
// int workManager::getEmpNum()
// {
//     ifstream ifs;
//     ifs.open(FILENAME,ios::in);
//     int id;
//     string name;
//     int dId;
//     int num=0;
//     while(ifs>>id&&ifs>>name&&ifs>>dId)
//     {
//         num++;
//     }
//     return num;
// }

// //初始化职工
// void workManager::initEmp()
// {
//     ifstream ifs;
//     ifs.open(FILENAME,ios::in);
//     int id;
//     string name;
//     int dId;
//     int index=0;
//     while(ifs>>id&&ifs>>name&&ifs>>dId)
//     {
//         Worker * worker=NULL;
//         if(dId==1)
//         {
//             worker=new Employee(id,name,dId);
//         }
//         else if(dId==2)
//         {
//             worker=new Manager(id,name,dId);
//         }
//         else
//         {
//             worker=new Boss(id,name,dId);
//         }
//         this->worker[index]=worker;
//         index++;
//     }
//     ifs.close();
// }

// //展示菜单
// void workManager::showMenu()
// {
//     cout<<"*********************************"<<endl;
//     cout<<"*****  欢迎使用职工管理系统  *****"<<endl;
//     cout<<"********  0.退出管理程序  ********"<<endl;
//     cout<<"********  1.增加职工信息  ********"<<endl;
//     cout<<"********  2.显示职工信息  ********"<<endl;
//     cout<<"********  3.删除离职职工  ********"<<endl;
//     cout<<"********  4.修改职工信息  ********"<<endl;
//     cout<<"********  5.查找职工信息  ********"<<endl;
//     cout<<"********  6.按照编号排序  ********"<<endl;
//     cout<<"********  7.清空所有文档  ********"<<endl;
//     cout<<"**********************************"<<endl;
//     cout<<endl;
// }

// //退出系统
// void workManager::exitSystem()
// {
//     cout<<"欢迎下次使用"<<endl;
//     exit(0);
// }

// //析构函数
// workManager::~workManager()
// {

// }

// //普通员工类构造函数
// Employee::Employee(int id,string name,int dId)
// {
//     this->m_Id=id;
//     this->m_Name=name;
//     this->m_DeptId=dId;
// }
// //显示普通员工个人信息
// void Employee::showInfo()
// {
//     cout<<"职工编号："<<this->m_Id
//         <<"\t职工姓名:"<<this->m_Name
//         <<"\t岗位:"<<this->getDeptId()
//         <<"\t岗位职责:完成经理交给的任务"<<endl;
// }
// //获取普通员工岗位名称
// string Employee::getDeptId()
// {
//     return string("普通员工");
// }

// //经理类构造函数
// Manager::Manager(int id,string name,int dId)
// {
//     this->m_Id=id;
//     this->m_Name=name;
//     this->m_DeptId=dId;
// }
// //显示经理个人信息
// void Manager::showInfo()
// {
//     cout<<"职工编号："<<this->m_Id
//         <<"\t职工姓名:"<<this->m_Name
//         <<"\t岗位:"<<this->getDeptId()
//         <<"\t岗位职责:完成老板交给的任务，并下发任务给员工"<<endl;
// }
// //获取经理岗位名称
// string Manager::getDeptId()
// {
//     return string("经理");
// }

// //老板类构造函数
// Boss::Boss(int id,string name,int dId)
// {
//     this->m_Id=id;
//     this->m_Name=name;
//     this->m_DeptId=dId;
// }
// //显示老板个人信息
// void Boss::showInfo()
// {
//     cout<<"职工编号："<<this->m_Id
//         <<"\t职工姓名:"<<this->m_Name
//         <<"\t岗位:"<<this->getDeptId()
//         <<"\t岗位职责:管理公司所有事务"<<endl;
// }
// //获取普通员工岗位名称
// string Boss::getDeptId()
// {
//     return string("老板");
// }

// //保存文件
// void workManager::save()
// {
//     ofstream ofs;
//     ofs.open("empFile.txt",ios::out);
//     if(!ofs.is_open())
//     {
//         cout<<"文件打开失败"<<endl;
//         return;
//     }
//     for(int i=0;i<this->m_EmpNum;i++)
//     {
//         ofs<<this->worker[i]->m_Id<<" "
//             <<this->worker[i]->m_Name<<" "
//             <<this->worker[i]->m_DeptId<<endl;
//     }
//     ofs.close();
// }

// //增加职工
// void workManager::addEmp()
// {
//     int addNum=0;
//     //提示用户输入增加职工数量
//     cout<<"请输入增加职工数量："<<endl;
//     cin>>addNum;
//     if(addNum>0)
//     {
//         //计算新空间大小
//         int newNum=this->m_EmpNum+addNum;
//         //开辟新空间
//         Worker ** newSpace=new Worker*[newNum];
//         //将原空间下数据存入新空间下
//         if(this->worker!=NULL)
//         {
//             for(int i=0;i<this->m_EmpNum;i++)
//             {
//                 newSpace[i]=this->worker[i];
//             }
//         }
//         //添加新数据
//         for(int i=0;i<addNum;i++)
//         {
//             int id;
//             string name;
//             int dSelect;
//             cout<<"请输入第"<<i+1<<"个新职工编号："<<endl;
//             cin>>id;
//             cout<<"请输入第"<<i+1<<"个新职工姓名："<<endl;
//             cin>>name;
//             cout<<"请选择该职工岗位："<<endl;
//             cout<<"1、普通员工"<<endl;
//             cout<<"2、经理"<<endl;
//             cout<<"3、老板"<<endl;
//             cin>>dSelect;
//             Worker * worker=NULL;
//             switch(dSelect)
//             {
//                 case 1:
//                     worker=new Employee(id,name,1);
//                     break;
//                 case 2:
//                     worker=new Manager(id,name,2);
//                     break;
//                 case 3:
//                     worker=new Boss(id,name,3);
//                     break;
//                 default:
//                     break;
//             }
//             newSpace[this->m_EmpNum+i]=worker;
//         }
//         //释放原有空间
//         delete[] this->worker;
//         //更改新空间的指向
//         this->worker=newSpace;
//         //更新新的职工人数
//         this->m_EmpNum=newNum;
//         //更新职工信息成功
//         cout<<"成功添加"<<addNum<<"名新职工"<<endl;
//         //保存数据到文件
//         this->save();

//         system("pause");
//         system("cls");
//     }
//     else
//     {
//         cout<<"输入数据有误"<<endl;
//     }
// }

// //显示职工
// void workManager::showEmp()
// {
//     if(this->fileIsEmpty==true)
//     {
//         cout<<"文件不存在或记录为空"<<endl; 
//     }
//     else
//     {
//         for(int i=0;i<this->m_EmpNum;i++)
//         {
//             this->worker[i]->showInfo();
//         }
//     }
//     system("pause");
//     system("cls");
// }

// //判断职工是否存在
// int workManager::isExist(int id)
// {
//     if(this->fileIsEmpty==true)
//     {
//         return -1;
//     }
//     else
//     {
//         for(int i=0;i<this->m_EmpNum;i++)
//         {
//             if(this->worker[i]->m_Id==id)
//             {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }
// //删除职工
// void workManager::delEmp()
// {
//     if(this->fileIsEmpty==true)
//     {
//         cout<<"文件不存在或记录为空"<<endl;
//     }
//     else
//     {
//         cout<<"请输入想要删除的职工编号："<<endl;
//         int id=0;
//         cin>>id;
//         int index=this->isExist(id);
//         if(index!=-1)
//         {
//             for(int i=index;i<this->m_EmpNum-1;i++)
//             {
//                 this->worker[i]=this->worker[i+1];
//             }
//             this->m_EmpNum--;
//             this->save();
//             cout<<"删除成功"<<endl;
//         }
//         else
//         {
//             cout<<"删除失败，未找到该职工"<<endl;
//         }
//     }
//     system("pause");
//     system("cls");
// }

// //修改职工
// void workManager::modEmp()
// {
//     if(this->fileIsEmpty==true)
//     {
//         cout<<"文件不存在或记录为空"<<endl;
//     }
//     else
//     {
//         cout<<"请输入想要修改的职工编号："<<endl;
//         int id=0;
//         cin>>id;
//         int index=this->isExist(id);
//         if(index!=-1)
//         {
//             delete this->worker[index];
//             int newId=0;
//             string newName="";
//             int dSelect=0;
//             cout<<"查到："<<id<<"号职工，请输入新职工编号："<<endl;
//             cin>>newId;
//             cout<<"请输入新姓名："<<endl;
//             cin>>newName;
//             cout<<"请选择岗位："<<endl;
//             cout<<"1、普通员工"<<endl;
//             cout<<"2、经理"<<endl;
//             cout<<"3、老板"<<endl;
//             cin>>dSelect;
//             Worker * worker=NULL;
//             switch(dSelect)
//             {
//                 case 1:
//                     worker=new Employee(newId,newName,1);
//                     break;
//                 case 2:
//                     worker=new Manager(newId,newName,2);
//                     break;
//                 case 3:
//                     worker=new Boss(newId,newName,3);
//                     break;
//                 default:
//                     break;
//             }
//             this->worker[index]=worker;
//             cout<<"修改成功"<<endl;
//             this->save();
//         }
//         else
//         {
//             cout<<"修改失败，未找到该职工"<<endl;
//         }
//     }
//     system("pause");
//     system("cls");
// }

// //查找职工
// void workManager::findEmp()
// {
//     if(this->fileIsEmpty==true)
//     {
//         cout<<"文件不存在或记录为空"<<endl;
//     }
//     else
//     {
//         cout<<"请输入查找的方式："<<endl;
//         cout<<"1、按照职工编号查找"<<endl;
//         cout<<"2、按照职工姓名查找"<<endl;
//         int select=0;
//         cin>>select;
//         if(select==1)
//         {
//             int id=0;
//             cout<<"请输入查找的职工编号："<<endl;
//             cin>>id;
//             int index=this->isExist(id);
//             if(index!=-1)
//             {
//                 this->worker[index]->showInfo();
//             }
//             else
//             {
//                 cout<<"未找到该职工"<<endl;
//             }
//         }
//         else if(select==2)
//         {
//             string name="";
//             cout<<"请输入查找的职工姓名："<<endl;
//             cin>>name;
//             bool flag=false;
//             for(int i=0;i<this->m_EmpNum;i++)
//             {
//                 if(this->worker[i]->m_Name==name)
//                 {
//                     this->worker[i]->showInfo();
//                     flag=true;
//                 }
//             }
//             if(flag==false)
//             {
//                 cout<<"未找到该职工"<<endl;
//             }
//         }
//         else
//         {
//             cout<<"输入有误"<<endl;
//         }
//     }
//     system("pause");
//     system("cls");
// }

// //按照编号排序
// void workManager::sortEmp()
// {
//     if(this->fileIsEmpty==true)
//     {
//         cout<<"文件不存在或记录为空"<<endl;
//     }
//     else
//     {
//         cout<<"请选择排序方式："<<endl;
//         cout<<"1、升序"<<endl;
//         cout<<"2、降序"<<endl;
//         int select=0;
//         cin>>select;
//         for(int i=0;i<this->m_EmpNum;i++)
//         {
//             int minOrMax=i;
//             for(int j=i+1;j<this->m_EmpNum;j++)
//             {
//                 if(select==1)
//                 {
//                     if(this->worker[minOrMax]->m_Id>this->worker[j]->m_Id)
//                     {
//                         minOrMax=j;
//                     }
//                 }
//                 else
//                 {
//                     if(this->worker[minOrMax]->m_Id<this->worker[j]->m_Id)
//                     {
//                         minOrMax=j;
//                     }
//                 }
//             }
//             if(i!=minOrMax)
//             {
//                 Worker * temp=this->worker[i];
//                 this->worker[i]=this->worker[minOrMax];
//                 this->worker[minOrMax]=temp;
//             }
//         }
//         cout<<"排序成功"<<endl;
//         this->save();
//         this->showEmp();
//     }
//     //system("pause");
//     //system("cls");
// }

// //清空所有文档
// void workManager::cleanFile()
// {
//     cout<<"确认清空？"<<endl;
//     cout<<"1、确认"<<endl;
//     cout<<"2、返回"<<endl;
//     int select=0;
//     cin>>select;
//     if(select==1)
//     {
//         ofstream ofs(FILENAME,ios::trunc);
//         ofs.close();
//         if(this->worker!=NULL)
//         {
//             for(int i=0;i<this->m_EmpNum;i++)
//             {
//                 if(this->worker[i]!=NULL)
//                 {
//                     delete this->worker[i];
//                     this->worker[i]=NULL;
//                 }
//             }
//             this->m_EmpNum=0;
//             delete[] this->worker;
//             this->worker=NULL;
//             this->fileIsEmpty=true;
//         }
//         cout<<"清空成功"<<endl;
//     }
//     system("pause");
//     system("cls");
// }
