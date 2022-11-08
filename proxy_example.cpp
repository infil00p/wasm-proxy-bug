#include <iostream>
#include <emscripten.h>
#include "thread_utils.h"
#include <emscripten/wasmfs.h>

extern "C" {
extern void set_id(em_proxying_ctx* ctx, uint32_t id);
extern void reset_id(em_proxying_ctx* ctx, uint32_t id);
}

int main() {
    emscripten::ProxyWorker proxy;

    auto wasmfs_backend = wasmfs_create_opfs_backend();

    std::cout << "Set the ID" << std::endl;
    proxy([&](auto ctx) { set_id(ctx.ctx, 1);});

    std::cout << "Back in C++, setting a flag" << std::endl;
    proxy([&](auto ctx) { reset_id(ctx.ctx, 3);});
    std::cout << "Back in C++ after attempting to unset the flag" << std::endl;

    return 0;
}
