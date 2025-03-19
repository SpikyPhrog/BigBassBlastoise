package(default_visibility = ["//visibility:public"])
load("@rules_pkg//:mappings.bzl", "pkg_files")

# Add any new asset folder in the glob function !!!
filegroup(
    name = "assets",
    srcs = glob(["fonts/*", "music/*", "dict/*"]),
)


pkg_files(
        name = "pkg_font_assets",
        srcs = glob(["fonts/*"]),
        prefix = "assets/fonts/",
)

pkg_files(
        name = "pkg_music_assets",
        srcs = glob(["music/*"]),
        prefix = "assets/music/",
)

pkg_files(
        name = "pkg_dict_assets",
        srcs = glob(["dict/*"]),
        prefix = "assets/dict/",
)