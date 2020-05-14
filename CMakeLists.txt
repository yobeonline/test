cmake_minimum_required ()
project(test)

set(CMAKE_CXX_STANDARD 17) # pour avoir std::filesystem

# Ajout de boost via find_package
if (MSVC)
  set(Boost_USE_STATIC_LIBS ON)
endif()
find_package(Boost REQUIRED filesystem) # génère la cible importée Boost::filesystem (cf la doc), attention à utiliser une version de cmake plus récente que celle de boost

# Ajout de gtest ia submodule (ie. inclusion du sous répertoire gtest qui contient le dépôt gtest)
if (MSVC)
	set(gtest_force_shared_crt on CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")
endif()
add_subdirectory(gtest) # génère la cible gtest_main (cf la doc)

# gtest n'est pas importé parce que la cible est compilée par le projet, Boost::filesystem est importé car le projet ne la compile pas.

add_executable(test test_filesystem.cpp)
target_link_libraries(test gtest_main Boost::filesystem) # ici la commande est mal nommée car il n'est pas nécessairement question de linker avec ces librairies.
# Par exemple on peut faire des cibles qui ne construisent rien mais qui injectent des définitions préprocesseur à tous ceux qui en dépendent.