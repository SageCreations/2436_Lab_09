# 2436_Lab_09

lab09 - Election Night Database

Since this is a presidential election year, I thought we would do a lab that simulates the electoral college maps that you might be seeing everywhere on election night. For instance, check out this popular website : ( https://www.270towin.com ) . This website is an electoral college simulator - it allows a user to vary the number of electoral college votes that each party receives ( Republican and Democrat ) to determine viable roads to 270 electoral votes - which is the number needed for a party to win the presidency. These same maps are used during election night by the broadcast networks to predict election winners. We will do the same.

Ok - so how does this relate to Computer Science? We are going to build the same data structures that the maps use - a Binary Search Tree. Note : we will NOT actually be drawing the maps, just the underlying data structure.

Our database will maintain nodes that will include:

1. an immutable stateID
2. an immutable electoral votes available count
3. current popular Republican vote count
4. current popular Democrat vote count

Our application will allow updating of popular vote counts for a state by an "encoded message" -> SSPXXXXXXXX where SS = State ID, P = Party, XX... is the popular vote count. We will simulate election night real-time updates. For instance, to send an update to the database, a message of TXR123456 would mean 123456 popular votes have been cast for the Republican party in the state of Texas.

Note : Maine and Nebraska split their votes - for simplicity - we will not split votes, if a party has a larger popular vote count, they all of the available electoral votes for that state

Note : We will assume there are only 2 parties in each state.

Note : Your election night database must not allow for decrementing of popular vote counts - no election hacking allowed !
