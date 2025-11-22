pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                echo 'Checking out repository...'
                checkout scm
            }
        }

        // !!! ВИДАЛЕНО stage('Restore NuGet') - його функцію перенесено в Build & Test !!!
        
        stage('Build & Restore') {
            steps {
                echo 'Restoring NuGet packages and Building solution with MSBuild...'
                // ВИКОРИСТАННЯ MSBuild З ПАРАМЕТРОМ /p:Restore=true
                // Зверніть увагу, що ми збираємо конфігурацію Release|x64
                bat '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /t:Build /p:Configuration=Release /p:Platform=x64 /p:Restore=true' 
            }
        }


        stage('Run Tests') {
            steps {
                echo 'Running tests (Release|x64)...'
                // УЗГОДЖЕННЯ: Змінено "Debug" на "Release", щоб відповідати попередньому етапу збірки.
                bat 'x64\\Release\\test_repos.exe --gtest_output="xml:test_report.xml"'
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
