add_rules("mode.debug", "mode.release")

add_requires("nlohmann_json")

target("jstp-server")
    set_kind("binary")
    add_files("src/*.cpp")
    add_syslinks("pthread")
    add_packages("nlohmann_json")
