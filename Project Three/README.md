Chada Tech Corner Grocer project:

    * Summarize the project and what problem it was solving.
      Chada Tech is making a program for Corner Grocery to help them analyze their produce sales. They want to know how many items of each kind of produce that they are selling each day. In order to accomplish this, they are writing down each piece of produce as it is sold. At the end of the day, that information is saved in a file, with each line holding a single item of produce. The file will be scanned in by our program, processed to analyze how many of each item were sold, save a backup of the sorted product, and then give the user some options to view the outcome in 3 different ways. They can supply an item of produce and get back how many of it were sold. They can choose to see the entire list of produce and how many of each were sold, or they can choose to see the same information, except as a historgram.
    * What did you do particularly well?
      I used a string to collect user input, rather than directly gathering it as an integer. This makes validating and error-checking the user input much easier and much easier to read. I did have to do some research to find out how C++ does type casting, but was very pleased with how easy std::stoi() is to use. 
    * Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
      I have a feeling that the order in which I laid out the class member functions could be better arranged, though I don't yet know what order that should be.
    * Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
      The most challenging part of this project would have been to do it without implementing Map. I hadn't used Map previously, so I was concerned about how to manage reading in the data, sorting and counting, and then using that for the various outputs. Instead, Map just... handled it. I did use cplusplus to make sure I was using Map and stoi() correctly. 
    * What skills from this project will be particularly transferable to other projects or course work?
      I believe that map and stoi() are very useful tools that I will be using again in the future.
    * How did you make this program maintainable, readable, and adaptable?
      I specified the input and output names as constants, so that if they need to be updated or used in additional future functions, that information will only have to be updated in one spot. I am pretty pleased with my variable and function naming. I think the code is fairly readable and that's mostly due to having well named variables.

As an entire project, Corner Grocer was significantly easier for me than Project Two. Part of that is due to the overly complicated way I used header files in Project Two. And part of it is because, while in Project Two I struggled to get the interest function to work correctly with additional monthly deposits, in Project Three, map just worked. 
