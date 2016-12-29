# Git 操作简易指南

作者：Frank King ([@whjpji](https://github.com/whjpji))

这里提供一个简易的git教程，大家可以在本地将解题笔记写好之后再上传。
这样做的好处是可以在本地保留一份代码，且更方便地同步本地和远程仓库。
并且，除了最后的pull request以外，所有操作均在本地完成，更加方便。

## 1. 从官方网站上下载并安装[git](https://git-scm.com/downloads)

对于Linux系统而言，可以直接使用包管理器来安装。

对于Windows系统而言，安装好git-bash后，以下所有命令均在git-bash中执行，
无需使用Windows系统自带的命令提示符软件。因此常用命令皆为Linux风格的命令，
最常见的如下：

| Linux (Git Bash) 命令 | 作用                      | 示例             |
|-----------------------|---------------------------|------------------|
| `cd`                  | 改变当前工作目录          | `cd ~/source`    |
| `mkdir`               | 新建文件夹                | `mkdir leetcode` |
| `rmdir`               | 删除**空**文件夹          | `rmdir leetcode` |
| `vim`                 | 使用vim编辑（或新建）文件 | `vim note.md`    |
| `rm`                  | 删除文件                  | `rm note.md`     |
| `rm -r`               | 删除文件夹                | `rm -r leetcode` |

在git-bash中，所有Windows的`C`, `D`, `E`, `F`盘都被映射到了`/c`, `/d`, `/e`, `/f`中，
即原来`C`盘的某个路径`C:\Users\foo`被映射到了`/c/Users/foo`中。

值得注意的是，git-bash具有命令自动补全的功能，如当输入`git com`之后，按下Tab键，
于是`git commit`命令就被自动补全了。

## 2. Fork，然后同步本地与远程仓库

Fork操作见[github操作指南](github操作指南.md)

### 第一次使用时将整个远程仓库下载到本地

这里可以直接使用`git clone`命令来下载整个代码仓库，方法是：

```bash
## 1. 进入自己存放代码的工作目录。
cd ~/Source
# 在Windows下，若使用git bash软件，可用以下命令进入到D, E, F盘的某个文件夹中。
# cd /e/Source

## 2. 下载远程仓库到本地。这里推荐大家从自己fork后的仓库中下载（将以下地址中的githubwoniu替换为自己的ID），以便后期的管理
git clone https://github.com/githubwoniu/learnprogram.git
# 若已有SSH key，使用ssh来下载将更加方便（生成SSH key的方法详见廖雪峰的博客）。
# git clone git@github.com:githubwoniu/learnprogram.git
```

### 以后更新时，无需重新下载整个仓库

使用`git pull`命令，增量更新：

```bash
git pull
```

若大家在clone时使用了自己fork之后的仓库地址，那么可以通过以下方法来更新：

```bash
## 1. 添加上游仓库的路径
git remote add upstream https://github.com/githubwoniu/learnprogram.git

## 2. 获取上游仓库
git fetch upstream

## 3. 与上游仓库的代码合并
git checkout master # 切换至主分支
git merge upstrea/master
```

## 3. 在本地建好的代码仓库中添加自己的解题笔记文件

以第一次刷题活动为例，进入到该题的[目录](leetcode/09)下，
然后新建文件（如note_githubwoniu.md），利用VIM、Emacs、notepad++、记事本
等任何文本编辑软件写好解题笔记，保存。

## 4. 提交写好的解题笔记到本地仓库

刚刚写好的文件还未被放入git仓库中去，需要手动提交。方法如下：

```bash
## 1. 将文件添加到暂存区
git add note_githubwoniu.md

## 2. 将暂存区的文件提交到版本库中（引号中的内容为提交的信息）
git commit -m "Add note_githubwoniu.md"
```

## 5. 将本地仓库的改动提交到远程仓库

方法很简单，一句

```bash
git push 
```

就好了。当然如果大家在clone的时候使用了上游的仓库地址，那么需要重新配置一下：

```bash
## 1. 将远程仓库重命名为上游仓库
git remote rename origin upstream

## 1. 重设远程仓库的地址为自己的远程仓库，并提交
# 注意将以下地址中的whjpji替换为自己的ID
git push origin -u https://github.com/whjpji/learnprogram.git
```

## 6. Pull Request

Pull request操作见[github操作指南](github操作指南.md)

# 参考资料

[廖雪峰的Git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)
