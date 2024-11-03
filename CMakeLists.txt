cmake_minimum_required(VERSION 3.10)

# プロジェクト名と使用する言語を設定
project(get_func_name LANGUAGES C)

# ソースファイルを指定
set(SOURCES
    get_func_name.c
)

# 実行ファイルを生成
add_executable(get_func_name ${SOURCES})

# コンパイルオプションを追加
target_compile_options(get_func_name PRIVATE -O0)

# リンクオプションを追加
target_link_libraries(get_func_name dl)
target_link_options(get_func_name PRIVATE -rdynamic)
