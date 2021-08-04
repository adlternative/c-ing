#include <cassert>
#include <leveldb/db.h>
#include <leveldb/status.h>

int main(int argc, char *argv[]) {
  leveldb::DB *db;              // 数据库操作句柄
  leveldb::Options opt;         // 设置选项
  opt.create_if_missing = true; // 不存在的情况下创建
  leveldb::Status status =
      leveldb::DB::Open(opt, "./db", &db); // Open操作
  assert(status.ok());                            // 断言操作后的状态
}