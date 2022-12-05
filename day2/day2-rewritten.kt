import java.io.File

fun main() {
	val infile = File("./day2.txt");
	var answer1 = 0;
	var answer2 = 0;

	infile.forEachLine {
		if (it[0] == 'A')
		{
			if (it[2] == 'Y')
				answer1 += (6 + 2);
			else if (it[2] == 'X')
				answer1 += (3 + 1);
			else if (it[2] == 'Z')
				answer1 += (0 + 3);

			if (it[2] == 'X')
				answer2 += 3 + 0;
			else if (it[2] == 'Y')
				answer2 += 1 + 3;
			else if (it[2] == 'Z')
				answer2 += 2 + 6;
		}
		else if (it[0] == 'B')
		{
			if (it[2] == 'X')
				answer1 += (0 + 1);
			else if (it[2] == 'Y')
				answer1 += (3 + 2);
			else if (it[2] == 'Z')
				answer1 += (6 + 3);

			if (it[2] == 'X')
				answer2 += 1 + 0;
			else if (it[2] == 'Y')
				answer2 += 2 + 3;
			else if (it[2] == 'Z')
				answer2 += 3 + 6;
		}
		else if (it[0] == 'C')
		{
			if (it[2] == 'Z')
				answer1 += (3 + 3);
			else if (it[2] == 'X')
				answer1 += (6 + 1);
			else if (it[2] == 'Y')
				answer1 += (0 + 2);

			if (it[2] == 'X')
				answer2 += 2 + 0;
			else if (it[2] == 'Y')
				answer2 += 3 + 3;
			else if (it[2] == 'Z')
				answer2 += 1 + 6;
		}
	}

	println("Answer 1: $answer1")
	println("Answer 2: $answer2")
}