import subprocess
import os

# 构建项目
print("Building project...")
result = subprocess.run(["D:\\APP\\Keil_5\\UV4\\UV4.exe", "-b", "Project.uvprojx"], cwd=os.getcwd())

# 检查构建结果
if result.returncode == 0:
    print("Build completed successfully!")
else:
    print("Build failed with error code:", result.returncode)

# 暂停以查看输出
input("Press Enter to continue...")