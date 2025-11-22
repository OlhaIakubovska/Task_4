pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                echo 'Checking out repository...'
                checkout scm
            }
        }

        stage('Restore NuGet') {
            steps {
                echo 'Restoring NuGet packages...'
                bat '"C:\\Program Files\\NuGet\\nuget.exe" restore test_repos.sln'
            }
        }

        stage('Build') {
            steps {
                echo 'Building solution with MSBuild...'
                bat '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /t:Build /p:Configuration=Release'
            }
        }


        stage('Run Tests') {
            steps {
                bat 'x64\\Debug\\test_repos.exe --gtest_output="xml:test_report.xml"'
            }
        }

        stage('Test Report') {
            steps {
                xunit {
                    googleTest(pattern: 'test_report.xml')
                }
            }
        }

    }
}
