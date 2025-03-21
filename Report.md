# Project 4 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project).
  * My data set contains 4106 records of UFC fighter data from name, wins, losses an draws to striking and defending statistics. The data was originally sorted by name, 
  but I resorted by height, and used name as the variable on which to sort during this project
* Analyze the data. Graph the number of reads and allocations for each sorting algorithm and look at how the number of reads and allocations grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.
* Look at the output from the stabilityTest function and answer the following questions:
  * How are the names sorted by default?
  * The names are initially sorted alphabetically by first name.
  * How is the output from the two stable sorting algorithms different from the two unstable ones? Be specific in your answer, and use what you know about how each sorting algorithm works to justify your observations.
* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
  * I would use merge sort as it has the lowest time complexity, with O(n log n) guaranteed.
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud
  * In this case, I would use merge sort as well, fir the same reason, with O(n log n) as the worst complexity.
**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**