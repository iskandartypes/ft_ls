# ft_ls

Recode of ls on a Unix system. Supports `-AFGRSTafgilnprstu` flags; see [man ls](http://man7.org/linux/man-pages/man1/ls.1.html) for what those do.

Should be able to download it, run `make`, and then use ft_ls to your heart's content (provided you've got GCC an make installed), although it's more an academic exercise than anything and you really probably shouldn't use it instead of your system ls.

Unfinished; currently having trouble with recurring properly on very large directories. There's also some structural repetition, and it currently outputs everything in single column format even in a terminal, similar to `ls -1`.
