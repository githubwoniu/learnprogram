这里尽量使用最简单的方式，让大家对Github和Git有所认识，基本能满足日常使用。

## 1. 注册账号并登录

和注册QQ号也没有多少区别，在第三步我们可以选择免费账户。免费账户也是可以创建代码仓库的。

## 2. Create a new repository

创建一个新的代码仓库

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/create_repository.png)

仓库里的内容是有记录的，往仓库添加内容、从仓库删除内容、修改仓库中文件的内容等都会记录在案


## 3. Fork

如果我们在逛街的时候，看到一件漂亮的衣服或者好玩的玩具想要据为己有，我们必须先考虑有没有足够的钱来买下它们。

在github上完全不存在这种情景，看到喜欢的可以随便往自己家里拿。这就是Fork。复制别人的仓库到自己的账号下。比如把nodejs的代码仓库拿回自己家

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/fork_other.png)

点击一下右上角的fork

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/fork_my.png)

注意观察左上角的账号变化。简单一点，自己名下就有一个同样的代码仓库了。

## 4. Edit

假如我们想要修改一下nodejs的说明文档，可以在自己家的仓库里进行修改。还记得吗，我们已经把它Fork回来了。

我们找到node/README.md，单击该文件

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/edit.png)

点击右上角的笔状图标就可以开始编辑了

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/edit2.png)

这个仓库是
[joyent/node](https://github.com/joyent/node)的一个拷贝。

我们可以把页面拖到底部来保存修改

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/commit.png)

commit是提交我们所做的修改到仓库中。

## 创建、上传文件

在个人仓库的主页，我们可以创建新文件，也可以直接上传本地文件到仓库中

### 创建新文件

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/create_file.png)

创建完成后，Commit

### 上传

Github支持上传不同格式的文件，只需要将本地文件拖动到指定窗口就可以了

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/upload.png)

同样的，记得Commit

如果我们上传一个同名的文件，会替换原有的文件。  
比如我们先把README.md下载下来，然后在本地进行修改，再把本地的一个README.md文件上传，这和直接在web上编辑是一样的效果

## 本地操作

如果不习惯在网站上修改文件，我们可以把代码下载下来，修改之后再上传。

![](https://github.com/githubwoniu/learnprogram/blob/master/image/github/download.png)

会把仓库代码打包下载到电脑。

## Pull Request

我们刚才所做的修改都只会在自己Fork的那份代码仓库里生效。  
也就是说，我们在这边改的热火朝天的，仓库的原主人并不知道有这么回事。  
如果我们想告诉仓库原主人我们所做的改动，就需要Pull Request来通知他  
仓库主人会比较两份文件来判断我们所做的改动是否有价值，他是完全有资格来拒绝我们的Pull的。

## 另外两种使用GitHub的姿势

上面的介绍中，我们的操作都是在浏览器中完成的，只是希望能够尽量简单明了的介绍git的一些基本概念。

在掌握了这些概念之后，我们鼓励大家尝试一下git命令或者其他图形工具(如github desktop)，尤其是git命令。

这里给大家两个好的参考链接

[廖雪峰的Git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

[怎样使用 GitHub](https://www.zhihu.com/question/20070065)，可以看下@珊姗是个小太阳 的回答，注意GitHub Desktop的安装需要能翻q

