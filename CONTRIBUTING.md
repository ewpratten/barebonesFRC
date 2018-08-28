# How to Contribute
Below, you can find the rules for pull requests and code reviews

## Creating your own branch
The only general rule for branch is to give your branches sensible names. 5024 members should refer to **the manual** for more rules specifically for the team.

## Protecting your branch (5024 only)
If you would like to protect your branch from other people merging into it without your permission, **add** the following to the bottom of the `CODEOWNERS` file in your branch
```
src/*       @<your username here>
```

## Merging to master
The master branch is write protected by default. Modifying the CODEOWNERS file will change who has access.

For 5024 members:

To merge to master, your code must first pass at least one code review. During the review (in most cases) your code must also properly function on the robot, and pass the checklist mentioned below. One of the master branch owners (mentors, or captains) must then approve your pull request.

## Coprocessers (5024 only)
Every coprocesser or laptop must have the code built for it stored in it's own repo. Talk to a mentor or captain for more details.

## The Checklist (5024 only)
For a change to pass the checklist, it must:

 - successfully build on the test server (we use circleci)
 - be able to work correctly 10 times in a row on both robots (this may be skipped with a mentor's permission during competitions)
 - if it contains any ARM or x86 assembly code, you must be able to prove that it will not segfault or coredump during operation
 - if it is computer vision related, 
