cmake_minimum_required(VERSION 3.10)

# プロジェクト名と使用する言語を設定
project(get_func_name LANGUAGES C)

# ソースファイルを指定
set(SOURCES
    get_func_name.c
)

# 実行ファイルを生成
add_executable(get_func_name ${SOURCES})
