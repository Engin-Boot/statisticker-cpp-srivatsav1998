# Compute Statistics

Here we compute statistics for a bunch of numbers.

This project uses the
[catch framework](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top)
to test functionality.

## Task

The task is to design a suitable return type to based on the tests designed

## Approach

I have designed a struct named Stats which holds three floating variables,
Average, min and max. I have designed custom functions to handle missing
values and also for calculating average, max and min of the passed value.