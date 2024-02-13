# Telegram-Desktop

There is a need for social media which can handle various functionalities with security and without any lags. It provides unique and popular functions which should meet the user requirements. I have created an application that can perform some functions such as downloading and searching the category, Text Messages, True caller bots, and so on. It provides large cloud storage to users and groups with a large number of users. Also resolving the difficulty in identifying a group chat from an individual chat. It removes bugs and errors. It provides regular updates based on feedback and new features.  
<h2>Function Details</h2>

<table>
  <tr>
    <th>SI. No.</th>
    <th>Function Name</th>
    <th>Description</th>
    <th>DS and Algorithm Used</th>
  </tr>
  <tr>
    <td>1.</td>
    <td>Hashing</td>
    <td>It is used to enter username and password.</td>
    <td>Hashing Data Structure</td>
  </tr>
  <tr>
    <td>2.</td>
    <td>Profile of User</td>
    <td>It is used to access the profile of users.</td>
    <td>Array data structure</td>
  </tr>
  <tr>
    <td>3.</td>
    <td>Text Messages</td>
    <td>It contains normal and schedule messages and schedule messages will be sent after scheduled time.</td>
    <td>Linked List Data Structure and File Data structure</td>
  </tr>
  <tr>
    <td>4.</td>
    <td>Download Media</td>
    <td>This function downloads all the type of categories which are available in app and used sleep function.</td>
    <td>File Data Structure</td>
  </tr>
  <tr>
    <td>5.</td>
    <td>Watching Downloads</td>
    <td>This function stores the downloaded file</td>
    <td>File Data Structure</td>
  </tr>
  <tr>
    <td>6.</td>
    <td>Auto Suggestion</td>
    <td>It suggests the mutual friends</td>
    <td>Matrix Data Structure</td>
  </tr>
  <tr>
    <td>7.</td>
    <td>Shortest path from cities</td>
    <td>To find shortest path from specific source to various destinations</td>
    <td>Graph Data Structure</td>
  </tr>
  <tr>
    <td>8.</td>
    <td>Search by username</td>
    <td>It is used to search people based on their username</td>
    <td>Search Data Structure and Brute Force Algorithm</td>
  </tr>
  <tr>
    <td>9.</td>
    <td>Nearby People</td>
    <td>It helps us to find users who are nearby to us based on distance</td>
    <td>Matrix Data Structure and Selection Sort Algorithm</td>
  </tr>
  <tr>
    <td>10.</td>
    <td>To find nearest person</td>
    <td>It helps us to find the person based on location who is free</td>
    <td>Graph Data Structure and Dijkstra’s Algorithm</td>
  </tr>
  <tr>
    <td>11.</td>
    <td>Celebrity fan following</td>
    <td>Displays the sorted celebrity names based on fan following</td>
    <td>Quick Sort Algorithm and File Data Structure</td>
  </tr>
  <tr>
    <td>12.</td>
    <td>Minimum Constraint Distance</td>
    <td>To find the minimum distance given by user and also to find the minimum weights covered when distance is given</td>
    <td>Graph Data Structure and Kruskal Algorithm</td>
  </tr>
  <tr>
    <td>13.</td>
    <td>True Caller Bot</td>
    <td>Displays the information about users when unknown contact number is given</td>
    <td>Boyer Moore Algorithm and Search Data Structure</td>
  </tr>
  <tr>
    <td>14.</td>
    <td>Auto Recommendation</td>
    <td>It automatically recommends media based on history</td>
    <td>Array Data Structure Linked List Data Structure</td>
  </tr>
  <tr>
    <td>15.</td>
    <td>To visit new websites</td>
    <td>It redirects to the website of that particular page</td>
    <td>Functionality used system start</td>
  </tr>
  <tr>
    <td>16.</td>
    <td>Enter into Mini dictionary</td>
    <td>Have words meanings stored in a file</td>
    <td>File Data Structure, Tree Data Structure [Binary Search Tree]</td>
  </tr>
  <tr>
    <td>17.</td>
    <td>Join Channel</td>
    <td>Joining the channel, deleting the channel as user needs</td>
    <td>Stack Data Structure</td>
  </tr>
</table>


<h2>Data Structures and Algorithms</h2>

<ul>
  <li>
    File data structure:
    <ul>
      <li>Acts like a server in the project.</li>
      <li>Used to store and retrieve data permanently.</li>
      <li>Helps in storing large amounts of data in trees and lists.</li>
    </ul>
  </li>
  <li>
    Hash Function:
    <ul>
      <li>Used in password checking.</li>
      <li>User can log in only if correct password is entered.</li>
      <li>Efficiency: O(1) (constant).</li>
    </ul>
  </li>
  <li>
    Doubly linked list:
    <ul>
      <li>Used to shuffle contacts based on recent messages sent by the user.</li>
      <li>Efficiency: O(number of contacts).</li>
    </ul>
  </li>
  <li>
    Matrix data structure:
    <ul>
      <li>Used to represent all nodes present in graphs.</li>
      <li>Used in algorithms like Kruskal, Dijkstra, and Floyd.</li>
      <li>Efficiency: O(n^2) where n is the number of nodes.</li>
    </ul>
  </li>
  <li>
    Dijkstra’s algorithm:
    <ul>
      <li>Used to find the nearest person in the project.</li>
      <li>Efficiency: O(E log(V)).</li>
    </ul>
  </li>
  <li>
    Floyd algorithm:
    <ul>
      <li>Used to include the feature of maps in the project.</li>
      <li>Finds the minimum distance from a city to all others.</li>
      <li>Efficiency: O(n^3).</li>
    </ul>
  </li>
  <li>
    Brute force string search:
    <ul>
      <li>Used to find city names in nearest city and in matching usernames.</li>
      <li>Efficiency: O(mn) where m is the length of the string and n is the length of the pattern.</li>
    </ul>
  </li>
  <li>
    Selection sort:
    <ul>
      <li>Used to sort people nearby based on distance.</li>
      <li>Efficiency: O(n^2).</li>
    </ul>
  </li>
  <li>
    Quick sort:
    <ul>
      <li>Named celebrity sort in the project because it sorts celebrities based on the number of followers.</li>
      <li>Efficiency in average case: O(n log(n)).</li>
    </ul>
  </li>
  <li>
    Kruskal’s algorithm:
    <ul>
      <li>Used to find the minimum distance given by the user.</li>
      <li>Efficiency: O(E log(E)).</li>
    </ul>
  </li>
  <li>
    Bayer Moore string search:
    <ul>
      <li>Used to search substrings in the true caller function.</li>
      <li>Matches phone numbers.</li>
      <li>Efficiency: O(mn) where m is the length of the string and n is the length of the pattern.</li>
    </ul>
  </li>
  <li>
    Array data structure:
    <ul>
      <li>Most parts of the program use this data structure to store names, numbers, and other details.</li>
      <li>Efficiency: O(n).</li>
    </ul>
  </li>
  <li>
    Binary search tree:
    <ul>
      <li>Used in the mini dictionary in the project.</li>
      <li>Stores all words and meanings and displays them lexicographically.</li>
      <li>Efficiency: O(log(n)).</li>
    </ul>
  </li>
  <li>
    Rabin carp:
    <ul>
      <li>Used to match usernames in the project.</li>
    </ul>
  </li>
</ul>
