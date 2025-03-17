package(default_visibility = ["//visibility:public"])
load("@rules_pkg//:mappings.bzl", "pkg_files")

# Add any new asset folder in the glob function !!!
filegroup(
    name = "assets",
    srcs = glob(["fonts/*", "music/*", "dict/*"]),
)


pkg_files(
        name = "pkg_assets",
        srcs = [":assets"],
        prefix = "assets/fonts/",
)