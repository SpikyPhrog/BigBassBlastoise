package(default_visibility = ["//visibility:public"])
#
MODULES = [
    "audio",
    "audio-d",
    "graphics",
    "graphics-d",
    "system",
    "system-d",
    "window",
    "window-d"
]

[
    cc_import(
        name = module,
        interface_library = "lib/sfml-{}.lib".format(module),
        shared_library = "bin/sfml-{}-3.dll".format(module),
    )
for module in MODULES]

filegroup(
    name = "dlls",
    srcs = glob(["bin/sfml-*-3.dll"]),
)

cc_library(
    name = "sfml",
    hdrs = glob([
        "include/SFML/**",
    ]),
    includes = ["include"],
    deps = MODULES,
)