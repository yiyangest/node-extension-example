#include <v8.h>
#include <node.h>

using namespace std;
using namespace v8;

static Handle<Value> foo(const Arguments& args){
    return String::New("hello world");
}

extern "C" {
    static void init(Handle<Object> target) {
        NODE_SET_METHOD(target, "foo", foo);
    }

    NODE_MODULE(hello, init);
}
