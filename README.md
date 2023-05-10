# VisitorArtEngagement
sudo mkdir /var/www/html/VisitorArtEngagement/  
sudo chown ubuntu /var/www/html/VisitorArtEngagement/ 

# SQL Table
Create table "visitorEngagement" in database "scmp318"

```
--
-- Database: `scmp318`
--

-- --------------------------------------------------------

--
-- Table structure for table `visitorEngagement`
--

CREATE TABLE `visitorEngagement` (
  `ID` int(11) NOT NULL,
  `Color` varchar(10) NOT NULL,
  `Timestamp` datetime NOT NULL DEFAULT current_timestamp(),
  `Location` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `visitorEngagement`
--

INSERT INTO `visitorEngagement` (`ID`, `Color`, `Timestamp`, `Location`) VALUES
(3, 'violet', '2023-05-04 17:34:00', 'Video'),
(4, 'red', '2023-05-04 17:52:52', 'Video'),
(5, 'violet', '2023-05-04 18:00:33', 'Kenyon'),
(6, 'violet', '2023-05-04 18:06:54', 'Video'),
(7, 'green', '2023-05-04 18:06:58', 'Video'),
(8, 'violet', '2023-05-04 18:07:03', 'Visit'),
(9, 'orange', '2023-05-04 18:07:07', 'Kenyon'),
(10, 'purple', '2023-05-04 18:07:11', 'Visit'),
(11, 'turquoise', '2023-05-04 18:07:16', 'Video'),
(12, 'green', '2023-05-04 18:07:19', 'Visit'),
(13, 'yellow', '2023-05-04 18:07:24', 'Kenyon'),
(14, 'red', '2023-05-04 18:07:27', 'Visit'),
(15, 'violet', '2023-05-04 18:11:19', 'Kenyon'),
(16, 'violet', '2023-05-04 19:00:35', 'Kenyon'),
(17, 'yellow', '2023-05-04 19:00:43', 'Visit'),
(18, 'purple', '2023-05-06 01:07:13', 'Video');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `visitorEngagement`
--
ALTER TABLE `visitorEngagement`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `visitorEngagement`
--
ALTER TABLE `visitorEngagement`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
```

**Columns**
* ID (integer - auto increment, primary key)
* Color (varchar 10)
* Timestamp (datetime - default current\_timestamp())
* Location (varchar 40)

# IP Address
Make sure to change the ip address to match your own in the following files:
* visEngage.js
* outputKenyon.js
* outputVisit.js
* outputVideo.js

# SQL Setup
Ensure that you have MariaDB and the C++ MariaDB connector downloaded

In db.h change the USER and PASS macros to be your own username and password for your MariaDB

# clearLoc Endpoint
The clearLoc endpoint is password protected with the password **_GallantGund_**

To use the endpoint type into the search bar *ip_address:5010/engage/clearLoc/Location/Password*
