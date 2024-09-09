cc_binary(
    name = "main",
    copts = [ "-pedantic"],
    srcs = ["main.cpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "test1",
    copts = [ "-pedantic","-DUSE_VAR"],
    srcs = ["main.cpp"],
    visibility = ["//visibility:public"],
    tags=["no-sandbox"]
)

cc_test(
    name = "test2",
    copts = [ "-pedantic",],
    srcs = ["main.cpp"],
    visibility = ["//visibility:public"],

)