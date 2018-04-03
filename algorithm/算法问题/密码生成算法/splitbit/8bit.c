#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

/*
* 8到15位密钥生成
*/
#define KEY_COUNT 35

typedef struct KEY_STRUCT{
  int   cur_dig_index;      // 当前的密钥位数
  char  key[16];            // 生成密钥
  int8_t  key_cur_index[16];  // 每一位密钥的当前索引
}KEY, *PKEY;
const char key_word[36] = {'a','b','c','d','e','f','g',
                           'h','i','j','k','l','m','n',
                           'o','p','q','r','s','t','u',
                           'v','w','x','y','z','1','2',
                           '3','4','5','6','7','8','9','0'};


void err_que(const char *msg)
{
  puts(msg);
  exit(0);
}

void err_sys(const char *msg)
{
  printf("%s:%s\n", msg, strerror(errno));
  exit(errno);
}


int key_modify(PKEY key);

int main(int argc, char const *argv[])
{
  int fd =0;          // 输出的文件描述符
  KEY key;            // 密钥信息
  int i;
  int flag = 0;         // 结束标志

  // 密钥信息初始化
  key.cur_dig_index = 7;

  for(i = 0; i < 16; i++)
  {
    if(i <= key.cur_dig_index)
    {
      key.key_cur_index[i]=0;
      key.key[i] = key_word[key.key_cur_index[i]];
    }
    else
    {
      key.key[i] = '\n';
      key.key_cur_index[i] = -1;
    }

  }

  // 创建写入文件
  if((fd = open("./8doc", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP)) == -1)
    err_sys("open error");

  while(1)
  {
    int first_cur_index = key.key_cur_index[0];   // 获取下标值
    first_cur_index++;

    if(first_cur_index <= KEY_COUNT)               // 更新下标
    {
        key.key_cur_index[0] = first_cur_index;
        key.key[0] = key_word[key.key_cur_index[0]];
    }
    else                                          // 修正信息表
      flag = key_modify(&key);

    if(write(fd, key.key, key.cur_dig_index+2) == -1)
      err_sys("write error");

    if(flag)
        break;
  }

  return 0;
}

int key_modify(PKEY key)
{
  int i;
  int first_cur_index = key->key_cur_index[0];

  if(first_cur_index < KEY_COUNT)
    return 0;

  // 从最低位置一次遍历
  for(i = 0; i < 9; i++)
  {
    if(key->key_cur_index[i] == KEY_COUNT)
    {
      key->key_cur_index[i] = 0;
      key->key[i] = key_word[key->key_cur_index[i]];
    }
    else
    {
      key->key_cur_index[i] ++;
      key->key[i] = key_word[key->key_cur_index[i]];

      if(key->cur_dig_index < i){
          key->cur_dig_index = i;
          write(STDOUT_FILENO, "写入下一位\n", strlen("写入下一位\n"));
      }
      break;
    }
  }

  if(i == 9)
    return 1;

  return 0;
}
