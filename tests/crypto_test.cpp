#include "crypto.hpp"
#include <cassert>

using namespace std;

int main() {
  
  // md5
  assert(Crypto::hex(Crypto::md5("Test")) == "0cbc6611f5540bd0809a388dc95a615b");
 
  // sha 1 
  assert(Crypto::hex(Crypto::sha1("Test")) == "640ab2bae07bedc4c163f679a746f7ab7fb5d1fa");
  assert(Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) == "af31c6cbdecd88726d0a9b3798c71ef41f1624d5");
  
  // sha256
  assert(Crypto::hex(Crypto::sha256("Test")) == "532eaabd9574880dbf76b9b8cc00832c20a6ec113d682299550d7a6e0f345e25");
  
  // sha512
  assert(Crypto::hex(Crypto::sha512("Test")) == "C6EE9E33CF5C6715A1D148FD73F7318884B41ADCB916021E2BC0E800A5C5DD97F5142178F6AE88C8FDD98E1AFB0CE4C8D2C54B5F37B30B7DA1997BB33B0B8A31");

  // pbkdf2
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 4096, 128 / 8)) == "f66df50f8aaa11e4d9721e1312ff2e66");
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 8192, 512 / 8)) == "a941ccbc34d1ee8ebbd1d34824a419c3dc4eac9cbc7c36ae6c7ca8725e2b618a6ad22241e787af937b0960cf85aa8ea3a258f243e05d3cc9b08af5dd93be046c");
}
