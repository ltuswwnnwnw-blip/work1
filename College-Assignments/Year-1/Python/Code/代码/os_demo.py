"""
os_demo.py —— Python os 模块完全教学代码

os 模块是 Python 和操作系统的"翻译官"：
  你想操作文件、目录、进程、环境变量 → 告诉 os → os 翻译成系统调用 → 操作系统干活

设计哲学：
  - 跨平台：同一套代码跑在 Windows / Linux / macOS 上，os 帮你处理底层差异
  - os.path 子模块：专门处理路径（Windows 用 \，Linux 用 /，os.path 自动适配）
  - 另有一个 os.path 的同名独立模块（import os.path），功能完全一样

按功能分成 10 大类，逐个讲解。
"""

import os       # ★ 核心模块：操作系统接口
import shutil   # 高级文件操作（复制、删除目录树），os 的补充
import stat     # 文件权限常量（S_IRUSR, S_IWUSR 等）
import time     # 时间相关（配合 os 获取文件时间戳）


# ===================================================================
# 第一类：路径操作（os.path）—— 用得最频繁的一类
# ===================================================================
#
# 核心问题：Windows 路径是 C:\foo\bar，Linux 是 /home/foo/bar
# 如果硬编码 \ 或 /，代码换平台就炸。os.path 帮你自动适配。

def demo_path():
    print("=" * 60)
    print("第一类：os.path 路径操作")
    print("=" * 60)

    # ---- 1.1 路径拼接 ----
    # os.path.join()：把多个部分拼成一个完整路径，自动插入正确的分隔符
    # 不用自己写 + "/" +，那样在 Windows 上会出错
    path = os.path.join("home", "lhh", "WORK", "C++", "os_demo.py")
    print(f"join 拼接: {path}")
    # Linux 输出: home/lhh/WORK/C++/os_demo.py
    # Windows 输出: home\lhh\WORK\C++\os_demo.py

    # ---- 1.2 路径拆分 ----
    # split()：把路径拆成 (目录部分, 文件名部分)
    # 返回元组 (head, tail)，tail 是最后一级
    dir_part, file_part = os.path.split(path)
    print(f"split 拆分: 目录={dir_part}, 文件={file_part}")
    # 输出: 目录=home/lhh/WORK/C++, 文件=os_demo.py

    # dirname()：只取目录部分（就是 split 的第一个元素）
    # basename()：只取文件名部分（就是 split 的第二个元素）
    print(f"dirname 目录: {os.path.dirname(path)}")
    print(f"basename 文件名: {os.path.basename(path)}")

    # splitext()：拆分文件扩展名，返回 (主名, 扩展名)
    root, ext = os.path.splitext("os_demo.py")
    print(f"splitext 扩展名: 主名={root}, 扩展名={ext}")
    # 输出: 主名=md8.1, 扩展名=.cpp

    # ---- 1.3 路径判断 ----
    # exists()：路径是否存在（文件和目录都算）
    print(f"exists 'os_demo.py' 存在吗? {os.path.exists('os_demo.py')}")
    # isfile()：是不是文件（不是目录）
    print(f"isfile 'os_demo.py' 是文件吗? {os.path.isfile('os_demo.py')}")
    # isdir()：是不是目录（不是文件）
    print(f"isdir '/home' 是目录吗? {os.path.isdir('/home')}")
    # isabs()：是不是绝对路径（以 / 或 C:\ 开头）
    print(f"isabs '/home/lhh' 绝对路径? {os.path.isabs('/home/lhh')}")
    print(f"isabs 'foo/bar' 绝对路径? {os.path.isabs('foo/bar')}")

    # ---- 1.4 路径转换 ----
    # abspath()：相对路径 → 绝对路径
    print(f"abspath '.' 绝对路径: {os.path.abspath('.')}")
    # relpath()：绝对路径 → 相对路径
    abs_path = os.path.abspath(".")
    print(f"relpath 转回相对: {os.path.relpath(abs_path, '/home')}")
    # normpath()：规范化路径（把 // 变 /，把 ./ 去掉，把 .. 解析掉）
    print(f"normpath 规范化: {os.path.normpath('/home//lhh/./WORK/../WORK/C++')}")

    # ---- 1.5 获取文件属性 ----
    # getsize()：文件大小（字节）
    print(f"getsize 'os_demo.py' 大小: {os.path.getsize('os_demo.py')} 字节")
    # getatime()：最后访问时间（access time）
    # getmtime()：最后修改时间（modify time）
    # getctime()：创建时间（create time / Windows 上是创建，Linux 上是属性变更）
    mtime = os.path.getmtime("os_demo.py")
    print(f"getmtime 最后修改: {time.ctime(mtime)}")


# ===================================================================
# 第二类：目录操作 —— 创建、删除、遍历
# ===================================================================

def demo_directory():
    print("\n" + "=" * 60)
    print("第二类：目录操作")
    print("=" * 60)

    # ---- 2.1 创建目录 ----
    # mkdir()：创建一级目录，如果上级目录不存在会报错
    os.makedirs("test_dir/sub_dir", exist_ok=True)
    # exist_ok=True：如果目录已存在不报错（Python 3.2+）
    print("mkdir 创建了 test_dir/sub_dir")

    # makedirs()：递归创建多级目录（中间不存在的目录一起创建）
    os.makedirs("a/b/c/d", exist_ok=True)
    print("makedirs 递归创建了 a/b/c/d")

    # ---- 2.2 获取当前目录 ----
    # getcwd()：get current working directory，当前工作目录
    print(f"getcwd 当前目录: {os.getcwd()}")
    # chdir()：change directory，切换工作目录
    os.chdir("test_dir")
    print(f"chdir 切换后: {os.getcwd()}")
    os.chdir("..")                     # 回到上一级
    print(f"chdir .. 回来: {os.getcwd()}")

    # ---- 2.3 列出目录内容 ----
    # listdir()：列出目录下所有文件和子目录名，返回列表
    contents = os.listdir(".")
    print(f"listdir 当前目录内容 ({len(contents)} 项):")
    for item in contents[:5]:          # 只展示前 5 个
        print(f"    {item}")
    if len(contents) > 5:
        print(f"    ... 还有 {len(contents) - 5} 项")

    # scandir()：和 listdir 一样但返回迭代器，每个元素有更多信息（性能更好）
    # 返回的是 DirEntry 对象，有 name、path、is_file()、is_dir()、stat() 等方法
    print("scandir 迭代目录（前 5 个）:")
    with os.scandir(".") as entries:   # with 自动清理资源
        count = 0
        for entry in entries:
            if count >= 5:
                break
            entry_type = "目录" if entry.is_dir() else "文件"
            print(f"    {entry.name} ({entry_type}, {entry.stat().st_size} 字节)")
            count += 1

    # ---- 2.4 遍历目录树 ----
    # walk()：递归遍历目录树，返回 (当前目录, 子目录列表, 文件列表)
    # 经典的 top-down 遍历，适合搜索文件
    print("\nwalk 遍历目录树:")
    for root, dirs, files in os.walk("test_dir"):
        print(f"  目录: {root}")
        for f in files:
            print(f"    文件: {f}")
        for d in dirs:
            print(f"    子目录: {d}")

    # ---- 2.5 删除目录 ----
    # rmdir()：删除空目录，目录非空会报错
    os.rmdir("a/b/c/d")
    os.rmdir("a/b/c")
    os.rmdir("a/b")
    os.rmdir("a")
    print("rmdir 删除了 a/ 下的空目录")
    # removedirs()：递归删除空目录（从叶子删到根）
    # shutil.rmtree()：删除非空目录（os 没这个功能，用 shutil）

    # ---- 2.6 重命名 ----
    # rename()：重命名文件或目录（也可以用来移动文件）
    # os.rename("test_dir/old.txt", "test_dir/new.txt")
    # os.renames()：递归重命名，自动创建中间目录


# ===================================================================
# 第三类：文件操作 —— 不是读写内容，是操作文件本身
# ===================================================================

def demo_file():
    print("\n" + "=" * 60)
    print("第三类：文件操作")
    print("=" * 60)

    # ---- 3.1 创建/删除文件 ----
    # 创建一个测试文件
    with open("test_os_demo.txt", "w") as f:
        f.write("hello os module\n第二行")

    # remove()：删除文件（不是目录）
    # os.remove("test_os_demo.txt")  # 先不删，后面演示用

    # ---- 3.2 重命名文件 ----
    # rename(src, dst)：把 src 重命名为 dst
    # 如果 dst 已存在，Windows 上会报错，Linux 上会覆盖
    with open("old_name.txt", "w") as f:
        f.write("test")
    os.rename("old_name.txt", "new_name.txt")
    print("rename: old_name.txt → new_name.txt")
    os.remove("new_name.txt")

    # ---- 3.3 文件状态信息 ----
    # stat()：获取文件的所有状态信息（大小、权限、时间戳、inode 等）
    st = os.stat("test_os_demo.txt")
    print(f"stat 文件大小: {st.st_size} 字节")         # 文件大小
    print(f"stat 权限位: {oct(st.st_mode)}")           # 权限（八进制）
    print(f"stat inode: {st.st_ino}")                  # inode 号（Linux）
    print(f"stat 硬链接数: {st.st_nlink}")             # 有多少个硬链接指向它
    print(f"stat 最后修改: {time.ctime(st.st_mtime)}") # 修改时间

    # 权限判断快捷方法
    print(f"access 是否可读? {os.access('test_os_demo.txt', os.R_OK)}")
    print(f"access 是否可写? {os.access('test_os_demo.txt', os.W_OK)}")
    print(f"access 是否可执行? {os.access('test_os_demo.txt', os.X_OK)}")

    # ---- 3.4 修改文件权限 ----
    # chmod()：修改文件权限（Unix 风格）
    # stat.S_IRUSR: 用户读, stat.S_IWUSR: 用户写, stat.S_IXUSR: 用户执行
    # 给用户添加执行权限
    current_mode = st.st_mode
    os.chmod("test_os_demo.txt", current_mode | stat.S_IXUSR)
    print("chmod 添加了用户可执行权限")


# ===================================================================
# 第四类：环境变量 —— 程序和系统的信息桥梁
# ===================================================================

def demo_environ():
    print("\n" + "=" * 60)
    print("第四类：环境变量")
    print("=" * 60)

    # os.environ：一个字典（dict-like 对象），存了所有环境变量
    # 读环境变量
    print(f"HOME 环境变量: {os.environ.get('HOME', '未设置')}")
    print(f"PATH 环境变量(前80字符): {os.environ.get('PATH', '未设置')[:80]}...")
    print(f"USER 环境变量: {os.environ.get('USER', '未设置')}")

    # getenv()：读取单个环境变量，比 environ.get() 更语义化
    print(f"getenv SHELL: {os.getenv('SHELL', '未设置')}")

    # putenv()：设置环境变量（只在当前进程及子进程生效，不影响系统）
    os.environ['MY_TEMP_VAR'] = 'hello_from_os'
    print(f"设置后 MY_TEMP_VAR = {os.getenv('MY_TEMP_VAR')}")

    # unsetenv()：删除环境变量
    del os.environ['MY_TEMP_VAR']
    print(f"删除后 MY_TEMP_VAR = {os.getenv('MY_TEMP_VAR', '已删除')}")


# ===================================================================
# 第五类：执行系统命令 —— Python 调用 shell
# ===================================================================

def demo_system_command():
    print("\n" + "=" * 60)
    print("第五类：执行系统命令")
    print("=" * 60)

    # system()：在子 shell 中执行命令，返回退出状态码
    # 优点：简单直接
    # 缺点：输出直接打印到屏幕，无法在程序里捕获；有安全风险（shell 注入）
    ret = os.system("echo 'hello from shell'")
    print(f"system 返回码: {ret} (0=成功)")

    # popen()：执行命令并获取输出（老式写法，返回文件对象）
    # 更推荐用 subprocess 模块（Python 3 起官方推荐）
    print("popen 执行 ls -l（前 3 行）:")
    with os.popen("ls -l | head -3") as pipe:
        for line in pipe:
            print(f"  {line}", end="")
    print()


# ===================================================================
# 第六类：进程管理 —— 程序自身的身份信息
# ===================================================================

def demo_process():
    print("\n" + "=" * 60)
    print("第六类：进程管理")
    print("=" * 60)

    # getpid()：当前进程 ID（PID）
    print(f"getpid 当前进程ID: {os.getpid()}")
    # getppid()：父进程 ID
    print(f"getppid 父进程ID: {os.getppid()}")
    # getuid() / getgid()：用户 ID / 组 ID（仅 Unix）
    print(f"getuid 用户ID: {os.getuid()}")
    print(f"getgid 组ID: {os.getgid()}")
    # getlogin()：登录用户名（需要 tty，无桌面/Docker 中可能报错）
    try:
        print(f"getlogin 登录用户: {os.getlogin()}")
    except OSError:
        print(f"getlogin 登录用户: 获取不到，用 getenv 代替: {os.getenv('USER')}")

    # cpu_count()：CPU 核心数
    print(f"cpu_count CPU核心数: {os.cpu_count()}")

    # uname()：系统信息（仅 Unix）
    uname_info = os.uname()
    print(f"uname 系统: {uname_info.sysname}, 主机: {uname_info.nodename}")
    print(f"uname 内核版本: {uname_info.release}, 架构: {uname_info.machine}")


# ===================================================================
# 第七类：文件描述符操作 —— 底层 IO（用得少但很重要）
# ===================================================================

def demo_fd():
    print("\n" + "=" * 60)
    print("第七类：文件描述符操作（底层 IO）")
    print("=" * 60)

    # open()：底层打开文件，返回文件描述符（整数），不是 Python 的 open()
    fd = os.open("test_os_demo.txt", os.O_RDONLY)  # 只读打开，返回整数
    print(f"open 文件描述符: {fd} (是一个整数)")

    # read()：从文件描述符读取指定字节数
    data = os.read(fd, 100)  # 读 100 字节
    print(f"read 读取内容: {data!r}")

    # lseek()：移动文件指针
    os.lseek(fd, 0, os.SEEK_SET)  # 移到开头
    print("lseek 指针移回开头")

    # fstat()：获取文件描述符对应的文件状态（和 stat() 一样但传 fd）
    st = os.fstat(fd)
    print(f"fstat 大小: {st.st_size} 字节")

    # ftruncate()：截断文件到指定长度
    # os.ftruncate(fd, 10)  # 把文件裁成 10 字节

    # fdatasync() / fsync()：强制把数据刷到磁盘
    # os.fsync(fd)

    # close()：关闭文件描述符
    os.close(fd)
    print("close 关闭了文件描述符")

    # ★ 文件描述符和 Python 的 open() 的关系：
    # Python open() 底层调用了 os.open()，返回的 _io.TextIOWrapper
    # 对象内部包含文件描述符，可以通过 file.fileno() 拿到


# ===================================================================
# 第八类：用户和权限
# ===================================================================

def demo_user_permission():
    print("\n" + "=" * 60)
    print("第八类：用户和权限")
    print("=" * 60)

    # 当前用户信息（仅 Unix/Linux/Mac）
    print(f"getuid 用户ID: {os.getuid()}")   # User ID
    print(f"geteuid 有效用户ID: {os.geteuid()}")  # 有效用户ID（setuid 程序用）
    print(f"getgid 组ID: {os.getgid()}")     # Group ID

    # 文件权限常量（配合 chmod 使用）
    # stat 模块提供了可读的权限常量
    print(f"S_IRUSR (用户读) = {oct(stat.S_IRUSR)}")  # 0o400
    print(f"S_IWUSR (用户写) = {oct(stat.S_IWUSR)}")  # 0o200
    print(f"S_IXUSR (用户执行)= {oct(stat.S_IXUSR)}")  # 0o100
    print(f"S_IRGRP (组读)   = {oct(stat.S_IRGRP)}")  # 0o040
    print(f"S_IROTH (其他读)  = {oct(stat.S_IROTH)}")  # 0o004
    # 组合：S_IRWXU = S_IRUSR | S_IWUSR | S_IXUSR（用户读写执行）


# ===================================================================
# 第九类：零散但常用的函数
# ===================================================================

def demo_misc():
    print("\n" + "=" * 60)
    print("第九类：零散但常用")
    print("=" * 60)

    # urandom(n)：生成 n 字节的加密级随机数（比 random 模块更安全）
    print(f"urandom 随机字节: {os.urandom(8)!r}")

    # linesep：当前平台的换行符
    # Windows: \r\n, Linux/Mac: \n
    print(f"linesep 换行符: {os.linesep!r}")

    # sep：路径分隔符
    # Windows: \, Linux/Mac: /
    print(f"sep 路径分隔符: {os.sep!r}")

    # pathsep：PATH 环境变量中的分隔符
    # Windows: ;, Linux/Mac: :
    print(f"pathsep 环境变量分隔符: {os.pathsep!r}")

    # extsep：扩展名分隔符（就是 .）
    print(f"extsep 扩展名分隔符: {os.extsep!r}")

    # devnull：空设备路径（类似 /dev/null）
    print(f"devnull 空设备: {os.devnull!r}")

    # get_exec_path()：返回 PATH 环境变量中的可执行文件搜索路径列表
    print(f"get_exec_path 前三项: {os.get_exec_path()[:3]}")

    # get_terminal_size()：获取终端窗口大小（行, 列）
    try:
        term_size = os.get_terminal_size()
        print(f"get_terminal_size 终端: {term_size.columns}列 x {term_size.lines}行")
    except OSError:
        print("get_terminal_size: 获取不到（可能在 IDE 中运行）")

    # strerror()：把错误码翻译成人话
    print(f"strerror(2) 错误码2: {os.strerror(2)}")   # "No such file or directory"
    print(f"strerror(13) 错误码13: {os.strerror(13)}") # "Permission denied"


# ===================================================================
# 第十类：创建/删除临时文件和目录
# ===================================================================

def demo_temp():
    print("\n" + "=" * 60)
    print("第十类：临时文件/目录")
    print("=" * 60)

    # ★ Python 3.2+ 推荐用 tempfile 模块，功能更全面
    # 但 os 也有基础的：

    # 临时文件的思路：
    # 1. 用 os.urandom() 生成随机文件名
    # 2. 创建文件
    # 3. 用完删除
    # 不推荐直接在 os 层做，用 tempfile 模块


# ===================================================================
# 附：os 模块中常用的属性和常量速查
# ===================================================================

def quick_reference():
    print("\n" + "=" * 60)
    print("速查表：os 常用属性和常量")
    print("=" * 60)

    constants = {
        "os.sep":       ("路径分隔符", os.sep),
        "os.linesep":   ("换行符", repr(os.linesep)),
        "os.pathsep":   ("PATH 分隔符", os.pathsep),
        "os.curdir":    ("当前目录符", os.curdir),
        "os.pardir":    ("上级目录符", os.pardir),
        "os.devnull":   ("空设备", os.devnull),
        "os.O_RDONLY":  ("只读标志", os.O_RDONLY),
        "os.O_WRONLY":  ("只写标志", os.O_WRONLY),
        "os.O_RDWR":    ("读写标志", os.O_RDWR),
        "os.O_CREAT":   ("创建标志", os.O_CREAT),
        "os.O_APPEND":  ("追加标志", os.O_APPEND),
        "os.R_OK":      ("可读检查", os.R_OK),
        "os.W_OK":      ("可写检查", os.W_OK),
        "os.X_OK":      ("可执行检查", os.X_OK),
    }
    for name, (desc, value) in constants.items():
        print(f"  {name:18s} {desc:12s} = {value}")


# ===================================================================
# 主函数：按需运行各演示函数
# ===================================================================

if __name__ == "__main__":
    demo_path()              # 路径操作（最常用）
    demo_directory()         # 目录操作
    demo_file()              # 文件操作
    demo_environ()           # 环境变量
    demo_system_command()    # 系统命令
    demo_process()           # 进程管理
    demo_fd()                # 文件描述符
    demo_user_permission()   # 用户和权限
    demo_misc()              # 零散函数
    demo_temp()              # 临时文件
    quick_reference()        # 速查表

    # 清理测试文件
    print("\n" + "=" * 60)
    print("清理测试文件...")
    for path in ["test_os_demo.txt", "a", "test_dir"]:
        if os.path.isfile(path):
            os.remove(path)
            print(f"  删除文件: {path}")
        elif os.path.isdir(path):
            shutil.rmtree(path)
            print(f"  删除目录: {path}")
    print("清理完成")
