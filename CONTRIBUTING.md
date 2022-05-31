> Merged from https://github.com/joelparkerhenderson/git_commit_message and https://chris.beams.io/posts/git-commit/

### General Rules

- Commit messages must have a subject line and may have body copy. These must be separated by a blank line.
- The subject line must not exceed 50 characters
- The subject line should be capitalized and must not end in a period
- The subject line must be written in imperative mood (*Fix*, not *Fixed* / *Fixes* etc.)
- The body copy must be wrapped at 72 columns
- The body copy must only contain explanations as to *what* and *why*, never *how*. The latter belongs in documentation and implementation.

### Example

This is an example of a complete commit message that adheres to this standard. Parts of this are optional, so read on.

```txt
Summarize changes in around 50 characters or less

More detailed explanatory text, if necessary. Wrap it to about 72
characters or so. In some contexts, the first line is treated as the
subject of the commit and the rest of the text as the body. The
blank line separating the summary from the body is critical (unless
you omit the body entirely); various tools like `log`, `shortlog`
and `rebase` can get confused if you run the two together.

Explain the problem that this commit is solving. Focus on why you
are making this change as opposed to how (the code explains that).
Are there side effects or other unintuitive consequences of this
change? Here's the place to explain them.

Further paragraphs come after blank lines.

 - Bullet points are okay, too

 - Typically a hyphen or asterisk is used for the bullet, preceded
   by a single space, with blank lines in between, but conventions
   vary here

If you use an issue tracker, put references to them at the bottom,
like this:

Resolves: #123
See also: #456, #789
```

### Subject and Body

- A body copy is not required for commits that are overly simple. If you find yourself repeating the subject line in the body copy, it's a good sign that the body might be superfluous.

To perform a *simple* commit, a single command if sufficient:

```sh
$ git commit -m"Fix my subject line style"
```

If you need to write copy, issue `git commit`. Git will now open your default text editor. To set a custom editor, use `git config --global core.editor nano` (in this example, nano is the editor).

Here's an example of a subject and body commit message:

```txt
Derezz the master control program

MCP turned out to be evil and had become intent on world domination.
This commit throws Tron's disc into MCP (causing its deresolution)
and turns it back into a chess game.
```

This makes browsing the git *log* easier:

```txt
$ git log
commit 42e769bdf4894310333942ffc5a15151222a87be
Author: Kevin Flynn <kevin@flynnsarcade.com>
Date:   Fri Jan 01 00:00:00 1982 -0200

 Derezz the master control program

 MCP turned out to be evil and had become intent on world domination.
 This commit throws Tron's disc into MCP (causing its deresolution)
 and turns it back into a chess game.
```

You can view a shorter log, by restricting the output to the subject lines:

```txt
$ git log --oneline
42e769 Derezz the master control program
```

This provied an easy way to get a quick overview by means of reading the shortlog:

```txt
$ git shortlog
Kevin Flynn (1):
      Derezz the master control program

Alan Bradley (1):
      Introduce security program "Tron"

Ed Dillinger (3):
      Rename chess program to "MCP"
      Modify chess program
      Upgrade chess program

Walter Gibbs (1):
      Introduce protoype chess program
```

### Use the Imperative

Inkeeping with the standard output of git itself, all commit subject lines must be written using the imperative:

**Good**

- Refactor subsystem X for readability
- Update getting started documentation
- Remove deprecated methods
- Release version 1.0.0

**Bad**

- Fixed bug with Y
- Changing behavior of X

***Very* Bad**

- More fixes for broken stuff
- Sweet new API methods
- 42

Your commit subject line must be able to complete the sentence

> If applied, this commit will ...

If it doesn't, it's non-conformant. The body may use any style you want.

## Use the Body to Explain the Background and Reasoning, not the Implementation

*Especially* if the diff is rather large or extremely clustered, you can save all fellow developers some time by explaining *why* you did *what*.

Here's a perfect example:

```txt
commit eb0b56b19017ab5c16c745e6da39c53126924ed6
Author: Pieter Wuille <pieter.wuille@gmail.com>
Date:   Fri Aug 1 22:57:55 2014 +0200

   Simplify serialize.h's exception handling

   Remove the 'state' and 'exceptmask' from serialize.h's stream
   implementations, as well as related methods.

   As exceptmask always included 'failbit', and setstate was always
   called with bits = failbit, all it did was immediately raise an
   exception. Get rid of those variables, and replace the setstate
   with direct exception throwing (which also removes some dead
   code).

   As a result, good() is never reached after a failure (there are
   only 2 calls, one of which is in tests), and can just be replaced
   by !eof().

   fail(), clear(n) and exceptions() are just never called. Delete
   them.
```

This is *way* easier to parse than the [corresponding diff](https://github.com/bitcoin/bitcoin/commit/eb0b56b19017ab5c16c745e6da39c53126924ed6.patch).

## Subject Line Standard Terminology

First Word | Meaning
--- | --
Add | Create a capability e.g. feature, test, dependency.
Cut | Remove a capability e.g. feature, test, dependency.
Fix | Fix an issue e.g. bug, typo, accident, misstatement.
Bump | Increase the version of something e.g. dependency.
Make | Change the build process, or tooling, or infra.
Start | Begin doing something; e.g. create a feature flag.
Stop | End doing something; e.g. remove a feature flag.
Refactor | A code change that MUST be just a refactoring.
Reformat | Refactor of formatting, e.g. omit whitespace.
Optimize | Refactor of performance, e.g. speed up code.
Document | Refactor of documentation, e.g. help files.

Subject lines must never contain (and / or start with) anything else. Especially not something that's unique to your system, like

- \[bug] ...
- (release) ...
- \#12345 ...
- jira://...
- docs: ...