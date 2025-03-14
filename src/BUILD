load("@rules_pkg//:pkg.bzl", "pkg_zip")

platform(
    name = "win_x64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
)

cc_binary(
        name="src",
        srcs = glob(["*.cpp", "*.h"]) + ["//src/widgets"],
        data = [
                "//src/assets",
        ],
        deps = [
                "@sfml",
                "@bazel_tools//tools/cpp/runfiles",
        ],
        copts = ["/std:c++17"],

)

pkg_zip(
        name = "package",
        srcs = [
                "//src",
                "//src/assets:pkg_assets",
                "@sfml//:dlls",
        ],
)