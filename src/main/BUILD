

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [],
)


cc_binary(
    name = "conditional_var_csp_main",
    srcs = ["conditional_var_csp_main.cc"],
    deps = ["//src/lib:csp_lib"],
)

cc_binary(
    name = "conditional_var_csp_sync_rcv_main",
    srcs = ["conditional_var_csp_sync_rcv_main.cc"],
    deps = ["//src/lib:csp_lib"],
)

cc_binary(
    name = "conditional_var_csp_adder_main",
    srcs = ["conditional_var_csp_adder_main.cc"],
    deps = ["//src/lib:csp_lib"],
)

cc_binary(
    name = "conditional_var_csp_adder_fork_join_main",
    srcs = ["conditional_var_csp_adder_fork_join_main.cc"],
    deps = ["//src/lib:csp_lib"],
)

cc_binary(
    name = "dining_philosophore_main",
    srcs = ["dining_philosophore_main.cc"],
    deps = ["//src/lib:csp_lib"],
)