# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is the longest word in the English language.

## According to its man page, what does `getrusage` do?

etrusage() returns the pointer to a struct containing the usage statistics of the program.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Because passing large structs by value is slow and takes up a lot of memory.
By passing by value we are making a copy of each struct, and that takes more time and space in stack.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

We start reading each word character by character till we reach the eand of the file.
For each alphapet, if it's an alphabetical character or an apostrophe not at index 0, we append the character to word.
we ignore strings, that more than 45 characters and the words with numbers.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

Because we want to check every word character by character and parse it's content. We dont want to read the whole word as one block.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

If you declare a variable to be a const, you're telling the compiler that it's a read-only variable and that it won't be changed throughout its existance.
