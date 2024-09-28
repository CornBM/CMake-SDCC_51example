# 查找所有的源文件
aux_source_directory(. C_SRCS)
# 生成可执行文件，名字为项目名
add_executable(${PROJECT_NAME} ${C_SRCS})

# 添加一个自定义命令，将.ihx文件转换为.hex文件
# 这个命令将在构建${PROJECT_NAME}时自动执行
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND packihx ${PROJECT_NAME}.ihx > ${PROJECT_SOURCE_DIR}/output/${PROJECT_NAME}.hex
    COMMENT "Generating HEX file from IHX file"
)