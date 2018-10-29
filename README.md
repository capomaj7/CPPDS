
关于配置文件在本地的一些操作
对于untrack的文件，我们可以创建.gitignore文件。
对于已经track的文件，我们可以这样做：
git update-index --assume-unchanged <files>
这样，即使已经更改了文件，用git status也不会看见文件已经更改。
但在使用时需要小心，取消这种设定可以使用：
git update-index --no-assume-unchanged <files>