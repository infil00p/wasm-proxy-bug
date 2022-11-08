mergeInto(LibraryManager.library, {
    set_id: async function(ctx, id) {
        id_var = id;
        console.log("We are setting a thread to" + id);
        _emscripten_proxy_finish(ctx);
    },
    reset_id: async function(ctx, id) {
        
        console.log("ID is currently" + id_var);
        id_var = id;
        console.log("We are setting a thread to" + id_var);
        _emscripten_proxy_finish(ctx);
    }
});