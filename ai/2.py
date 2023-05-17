import random

class Environment(object):

    def __init__(self):

        self.locationCondition = {'A': '0', 'B': '0'}

        self.locationCondition['A'] = random.randint(0, 1)

        self.locationCondition['B'] = random.randint(0, 1)

class SimpleReflexVacuumAgent(Environment):

    def __init__(self, environment):

        super().__init__()

        print(environment.locationCondition)

        Score = 0

        vacuumLocation = random.randint(0, 1)

        if vacuumLocation == 0:

            print("Vacuum is randomly placed at Location A")

            if environment.locationCondition['A'] == 1:

                print("Location A is Dirty.")

                environment.locationCondition['A'] = 0

                Score += 1

                print("Location A has been Cleaned. :D")

            if environment.locationCondition['B'] == 1:

                print("Location B is Dirty.")

                print("Moving to Location B...")

                Score -= 1

                environment.locationCondition['B'] = 0

                Score += 1

                print("Location B has been Cleaned. :D")

        else:

            if environment.locationCondition['B'] == 1:

                print("Location B is Dirty.")

                Score -= 1

                print("Moving to Location B...")

                environment.locationCondition['B'] = 0

                Score += 1

                print("Location B has been Cleaned. :D")

        if vacuumLocation == 1:

            print("Vacuum is randomly placed at Location B.")

            if environment.locationCondition['B'] == 1:

                print("Location B is Dirty")

                environment.locationCondition['B'] = 0

                Score += 1

                print("Location B has been Cleaned")

            if environment.locationCondition['A'] == 1:

                print("Location A is Dirty")

                Score -= 1

                print("Moving to Location A")

                environment.locationCondition['A'] = 0

                Score += 1

                print("Location A has been Cleaned")

        else:

            if environment.locationCondition['A'] == 1:

                print("Location A is Dirty")

                print("Moving to Location A")

                Score -= 1

                environment.locationCondition['A'] = 0

                Score += 1

                print("Location A has been Cleaned")

        print(environment.locationCondition)

        print("Performance Measurement: " + str(Score))

theEnvironment = Environment()

theVacuum = SimpleReflexVacuumAgent(theEnvironment)
